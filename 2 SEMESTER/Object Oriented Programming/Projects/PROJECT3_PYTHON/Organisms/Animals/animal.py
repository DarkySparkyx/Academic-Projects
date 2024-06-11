from Organisms.organism import Organism


class Animal(Organism):
    def __init__(self, position_x, position_y, name, symbol, strength, initiative, world, speed, color):
        super().__init__(position_x, position_y, name, symbol, strength, initiative, world, speed, color)

    def isshielding(self):
        return False
