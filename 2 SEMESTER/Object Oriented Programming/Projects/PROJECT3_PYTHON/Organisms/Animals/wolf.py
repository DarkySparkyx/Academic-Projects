from Organisms.Animals.animal import Animal


class Wolf(Animal):
    def __init__(self, position_x, position_y, world):
        super().__init__(position_x, position_y, "Wolf", 'W', 5, 5, world, 1, (100, 100, 100))
