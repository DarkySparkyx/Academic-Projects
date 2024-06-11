import sys

import pygame
from Organisms.Animals.wolf import Wolf

WHITE = (255, 255, 255)
BLACK = (0, 0, 0)


class World:
    def __init__(self, sizeX, sizeY):
        self.sizeX = sizeX
        self.sizeY = sizeY
        self.organisms = []
        self.addOrganism(Wolf(0,0,self))



    def addOrganism(self, organism):
        self.organisms.append(organism)


class Game:
    def __init__(self, sizeX, sizeY):
        self.world = World(sizeX, sizeY)

        window_width = 800
        window_height = 600
        window_size = (window_width, window_height)
        pygame.init()
        pygame.display.set_caption('The Game')
        self.screen = pygame.display.set_mode(window_size)
        self.screen.fill(WHITE)
        pygame.display.flip()

    def start(self):
        running = True
        self.screen.fill(WHITE)
        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                    pygame.quit()
                    sys.exit()
                elif event.type == pygame.KEYDOWN:
                    print(event.key)
                    for org in self.world.organisms:
                        org.action()
                        self.paintWorld()

    def paintWorld(self):
        self.screen.fill(WHITE)
        for i in range(0, self.world.sizeX):
            for j in range(0, self.world.sizeY):
                pygame.draw.rect(self.screen, BLACK, (20 * i, 20 * j, 20, 20), 1)

        for org in self.world.organisms:
            pygame.draw.rect(self.screen, org.color, (20 * org.position_x, 20 * org.position_y, 20, 20), 0)
        pygame.display.flip()
