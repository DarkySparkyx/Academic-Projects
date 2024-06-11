from Organisms.Plants.plant import Plant


class Grass(Plant):
    def __init__(self, position_x, position_y, world):
        super().__init__(position_x, position_y, "Grass", 'G', 0, 0, world, 0, (0, 255, 0))

    def getchild(self, newposition):
        return Grass(newposition[0], newposition[1], self.world)
