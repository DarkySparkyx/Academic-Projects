import random

class Organism:
    def __init__(self, position_x, position_y, name, symbol, strength, initiative, world, speed,color):

        if position_x == 0 & position_y == 0:
            self.position_x = random.randint(1, world.sizeX)
            self.position_y = random.randint(1, world.sizeY)
        else:
            self.position_x = position_x
            self.position_y = position_y

        self.name = name
        self.symbol = symbol
        self.strength = strength
        self.initiative = initiative
        self.world = world
        self.alive = True
        self.speed = speed
        self.color=color

    def action(self):
        newx = self.position_x + random.randint(-1,1)*self.speed
        newy = self.position_y + random.randint(-1,1)*self.speed
        while(newx == self.position_x and newy == self.position_y):
            newx = self.position_x + random.randint(-1, 1) * self.speed
            newy = self.position_y + random.randint(-1, 1) * self.speed

        self.position_x = newx
        self.position_y = newy



    def collision(self, attacker):
        pass

    def kill(self):
        self.alive = False
        self.position_x = 0
        self.position_y = 0
