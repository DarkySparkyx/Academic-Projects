import random

from Organisms.Animals.animal import Animal


class Turtle(Animal):
    def __init__(self, position_x, position_y, world):
        super().__init__(position_x, position_y, "Turtle", 'T', 2, 1, world, 1, (30, 253, 255))

    def getchild(self, newposition):
        return Turtle(newposition[0], newposition[1], self.world)

    def isshielding(self, attacker):
        if attacker.strength < 5:
            return True
        else:
            return False

    def action(self):
        i = random.randint(1,4)
        if i == 1:
            super().action()