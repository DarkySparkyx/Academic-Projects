from Organisms.Plants.plant import Plant


class Guarana(Plant):
    def __init__(self, position_x, position_y, world):
        super().__init__(position_x, position_y, "Guarana", 'G', 0, 0, world, 0, (255, 192, 203))

    def getchild(self, newposition):
        return Guarana(newposition[0], newposition[1], self.world)

    def planteffect(self, attacker):
        attacker.strength += 5
        self.world.logs.append(self.tostring() + " wzmacnia " + attacker.tostring())