from Organisms.Plants.plant import Plant


class Dandelion(Plant):
    def __init__(self, position_x, position_y, world):
        super().__init__(position_x, position_y, "Dandelion", 'D', 0, 0, world, 0, (255,255,0))

    def getchild(self, newposition):
        return Dandelion(newposition[0], newposition[1], self.world)

    def action(self):
        for i in range(0,3):
            super().action()
