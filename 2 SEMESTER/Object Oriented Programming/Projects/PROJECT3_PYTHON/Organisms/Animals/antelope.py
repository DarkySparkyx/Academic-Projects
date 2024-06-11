import random

from Organisms.Animals.animal import Animal


class Antelope(Animal):
    def __init__(self, position_x, position_y, world):
        super().__init__(position_x, position_y, "Antelope", 'A', 4, 4, world, 2, (139, 69, 19))

    def getchild(self, newposition):
        return Antelope(newposition[0], newposition[1], self.world)

    def isescaping(self):
        i = random.randint(0, 1)
        if ( i == 1 ):
            return True
        else:
            return False