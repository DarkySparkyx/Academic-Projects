from Organisms.Animals.animal import Animal


class Cybersheep(Animal):
    def __init__(self, position_x, position_y, world):
        super().__init__(position_x, position_y, "Cybersheep", 'C', 11, 4, world, 1, (0, 0, 255))
