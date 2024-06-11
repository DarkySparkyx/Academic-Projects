import random

from Organisms.organism import Organism


class Plant(Organism):
    def __init__(self, position_x, position_y, name, symbol, strength, initiative, world, speed, color):
        super().__init__(position_x, position_y, name, symbol, strength, initiative, world, speed, color)

    def action(self):
        if self.world.isbreedingpossible(self):
            i = random.randint(1, 50)
            print(i)
            if i == 1:
                childposition = self.world.findplaceforkid(self)
                self.world.addorganism(self.getchild(childposition))
                self.world.logs.append(self.tostring() + " rozmnaża się. Dziecko pojawi się na " + str(childposition))


    def collision(self, attacker):
        if attacker.strength > self.strength:
            self.world.logs.append(attacker.tostring() + " zjada " + self.tostring())
            attacker.position_x = self.position_x
            attacker.position_y = self.position_y
            self.kill()
            self.planteffect(attacker)
        else:
            self.world.logs.append(attacker.tostring() + " zjada " + self.tostring() + " i ginie.")
            self.kill()
            attacker.kill()

    def planteffect(self, attacker):
        pass
