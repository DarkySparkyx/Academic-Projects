from Organisms.Animals.animal import Animal


class Sheep(Animal):
    def __init__(self, position_x, position_y, world):
        super().__init__(position_x, position_y, "Sheep", 'S', 4, 4, world, 1, (211, 211, 211))

    def getchild(self, newposition):
        return Sheep(newposition[0], newposition[1], self.world)