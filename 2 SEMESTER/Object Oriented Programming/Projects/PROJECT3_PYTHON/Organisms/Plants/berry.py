from Organisms.Plants.plant import Plant


class Berry(Plant):
    def __init__(self, position_x, position_y, world):
        super().__init__(position_x, position_y, "Jagoda", 'B', 99, 0, world, 0, (139,0,139))

    def getchild(self, newposition):
        return Berry(newposition[0], newposition[1], self.world)
