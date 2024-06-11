from Organisms.Plants.plant import Plant
import math
from Organisms.Animals.animal import Animal

class Pineborscht(Plant):
    def __init__(self, position_x, position_y, world):
        super().__init__(position_x, position_y, "Barszcz", 'B', 10, 0, world, 0, (255, 0, 0))

    def getchild(self, newposition):
        return Pineborscht(newposition[0], newposition[1], self.world)

    def action(self):
        for i in range(-1, 2):
            for j in range(-1, 2):
                print("Skanowanie " + str(i) + " - " + str(j))
                if(self.world.isplacetaken(self.position_x+i, self.position_y+j)):
                    victim = self.world.findorganismbyposition(self.position_x+i, self.position_y+j)
                    if isinstance(victim, Animal) and not isinstance(victim, Cybersheep):
                        self.world.logs.append(self.tostring() + " zabija " + victim.tostring())
                        victim.kill()

        super().action()

class Cybersheep(Animal):
    def __init__(self, position_x, position_y, world):
        super().__init__(position_x, position_y, "Cybersheep", 'C', 11, 4, world, 1, (0, 0, 255))

    def getchild(self, newposition):
        return Cybersheep(newposition[0], newposition[1], self.world)

    def action(self):

        barszcze = []
        index = 0
        mindistance = self.world.sizeX * self.world.sizeY

        for org in self.world.organisms:
            if isinstance(org, Pineborscht):
                barszcze.append(org)
        if barszcze.__len__() == 0:
            super().action()
        else:
            for b in barszcze:
                xdistance = b.position_x - self.position_x
                ydistance = b.position_y - self.position_y
                distance = math.sqrt(xdistance ** 2 + ydistance ** 2)
                if distance < mindistance:
                    mindistance = distance
                    index = b
            newx = 0
            newy = 0

            if index.position_x > self.position_x:
                newx = self.position_x + 1
            if index.position_y > self.position_y:
                newy = self.position_y + 1
            if index.position_x < self.position_x:
                newx = self.position_x - 1
            if index.position_y < self.position_y:
                newy = self.position_y - 1
            if index.position_x == self.position_x:
                newx = self.position_x
            if index.position_y == self.position_y:
                newy = self.position_y
            print("Najblizszy barszcz to " + b.tostring() + " wiec ide w kierunku " + str(newx) + " x " + str(newy))
            if self.world.isplacetaken(newx, newy):
                ofiara = self.world.findorganismbyposition(newx, newy)
                ofiara.collision(self)
            else:
                self.world.logs.append(self.tostring() + " skacze na " + str(newx) + " " + str(newy))
                self.position_x = newx
                self.position_y = newy