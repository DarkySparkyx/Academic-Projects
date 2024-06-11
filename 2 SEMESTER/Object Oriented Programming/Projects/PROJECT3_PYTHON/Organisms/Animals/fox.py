from Organisms.Animals.animal import Animal


class Fox(Animal):
    def __init__(self, position_x, position_y, world):
        super().__init__(position_x, position_y, "Fox", 'F', 3, 7, world, 1, (255, 69, 0))

    def getchild(self, newposition):
        return Fox(newposition[0], newposition[1], self.world)