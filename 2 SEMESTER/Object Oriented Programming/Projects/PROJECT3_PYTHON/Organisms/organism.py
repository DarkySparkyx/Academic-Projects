import random


class Organism:
    def __init__(self, position_x, position_y, name, symbol, strength, initiative, world, speed, color):

        if position_x == -1 & position_y == -1:
            self.position_x = random.randint(0, world.sizeX-1)
            self.position_y = random.randint(0, world.sizeY-1)
        else:
            self.position_x = position_x
            self.position_y = position_y

        self.name = name
        self.symbol = symbol
        self.strength = strength
        self.initiative = initiative
        self.world = world
        self.alive = True
        self.speed = speed
        self.color = color

    def action(self):
        self.world.logs.append("Teraz kolej " + self.tostring())
        newx = self.position_x + random.randint(-1, 1) * self.speed
        newy = self.position_y + random.randint(-1, 1) * self.speed
        while newx == self.position_x and newy == self.position_y or not self.world.ispositiongood(newx, newy):
            newx = self.position_x + random.randint(-1, 1) * self.speed
            newy = self.position_y + random.randint(-1, 1) * self.speed

        if self.world.isplacetaken(newx, newy):
            ofiara = self.world.findorganismbyposition(newx, newy)
            ofiara.collision(self)
        else:
            self.world.logs.append(self.tostring() + " skacze na " + str(newx) + " " + str(newy))
            self.position_x = newx
            self.position_y = newy

    def collision(self, attacker):
        if attacker.symbol == self.symbol:
            if self.world.isbreedingpossible(self):
                newposition = self.world.findplaceforkid(self)
                print(newposition)
                self.world.addorganism(self.getchild(newposition))
                self.world.logs.append(self.tostring() + " rozmnaża się z " + attacker.tostring() + ". Dziecko pojawi się na pozycji " + str(newposition[0]) + " " + str(newposition[1]))
            else:
                self.world.logs.append(self.tostring() + " próbował się rozmnożyć z " + attacker.tostring() + ", ale nie ma miejsca na potomka. ")
        else:
            if attacker.strength >= self.strength:
                if(self.isshielding()):
                    self.world.logs.append(attacker.tostring() + " atakuje " + self.tostring() + " ale ofiara odpiera atak")
                elif self.isescaping() and self.world.isbreedingpossible(self):
                    attacker.position_x = self.position_x
                    attacker.position_y = self.position_y
                    newposition = self.world.findplaceforkid(self)
                    self.position_x = newposition[0]
                    self.position_y = newposition[1]
                else:
                    self.world.logs.append(attacker.tostring() + " zjada " + self.tostring() + ". " + self.tostring() + " ginie.")
                    attacker.position_x = self.position_x
                    attacker.position_y = self.position_y
                    self.kill()
            else:
                self.world.logs.append(attacker.tostring() + " natrafil na silniejszego " + self.tostring() + " i zginal.")
                attacker.kill()

    def isshielding(self):
        return False
    def isescaping(self):
        return False
    def kill(self):
        self.alive = False
        self.position_x = -1
        self.position_y = -1

    def tostring(self):
        return self.name + "(" + str(self.position_x) + ", " + str(self.position_y) + ")"

    def getchild(self, newposition):
        pass