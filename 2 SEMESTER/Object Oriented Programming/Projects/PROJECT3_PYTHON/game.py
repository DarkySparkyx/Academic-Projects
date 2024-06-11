import sys
import pickle
import pygame

from Organisms.Animals.antelope import Antelope

from Organisms.Animals.fox import Fox
from Organisms.Animals.human import Human
from Organisms.Animals.sheep import Sheep
from Organisms.Animals.turtle import Turtle
from Organisms.Animals.wolf import Wolf
from Organisms.Plants.berry import Berry
from Organisms.Plants.dandelion import Dandelion
from Organisms.Plants.grass import Grass
from Organisms.Plants.guarana import Guarana
from Organisms.Plants.pineborscht import Pineborscht
from Organisms.Plants.pineborscht import Cybersheep

WHITE = (255, 255, 255)
BLACK = (0, 0, 0)


class World:
    def __init__(self, sizeX, sizeY, game):
        self.sizeX = sizeX
        self.sizeY = sizeY
        self.organisms = []
        self.addorganism(Wolf(-1,-1,self))
        self.addorganism(Fox(-1,-1,self))
        self.addorganism(Human(-1,-1,self))
        self.addorganism(Sheep(-1,-1,self))
        self.addorganism(Cybersheep(-1,-1,self))
        self.addorganism(Turtle(-1,-1,self))
        self.addorganism(Antelope(-1,-1,self))
        self.addorganism(Grass(-1,-1,self))
        self.addorganism(Dandelion(-1,-1,self))
        self.addorganism(Pineborscht(-1,-1,self))
        self.addorganism(Berry(-1,-1,self))
        self.addorganism(Guarana(-1,-1,self))
        self.logs = []
        self.game = game
    def findorganismbyposition(self, x, y):
        for o in self.organisms:
            if o.position_x == x and o.position_y == y:
                return o
        return "NULL"

    def ispositiongood(self, x, y):
        if 0 <= x < self.sizeX and 0 <= y < self.sizeY:
            return True
        else:
            return False

    def garbagecollector(self):
        for o in self.organisms:
            if not o.alive:
                self.organisms.remove(o)
        self.organisms.sort(key=lambda organism: organism.initiative, reverse=True)
        self.logs.clear()

    def addorganism(self, organism):
        self.organisms.append(organism)

    def isplacetaken(self, x, y):
        for o in self.organisms:
            if o.position_x == x and o.position_y == y:
                return True

    def isbreedingpossible(self,parent):
        for i in range(-1, 1):
            for j in range(-1, 1):
                if self.ispositiongood(parent.position_x + i, parent.position_y + j) and not self.isplacetaken(parent.position_x + i, parent.position_y + j):
                    return True
        return False
    def findplaceforkid(self, parent):
        for i in range(-1, 1):
            for j in range(-1, 1):
                if self.ispositiongood(parent.position_x + i, parent.position_y + j) and not self.isplacetaken(parent.position_x + i, parent.position_y + j):
                    return ( parent.position_x + i, parent.position_y + j )

    def nextRound(self):
        i = len(self.organisms)
        for j in range(0, i):
            if self.organisms[j].alive:
                self.organisms[j].action()

    def __getstate__(self):
        # Serializacja stanu bez pola gra
        state = self.__dict__.copy()
        del state['game']  # Usunięcie pola, którego nie chcemy zapisywać
        return state


class Game:
    def __init__(self, sizeX, sizeY, fromfile):
        if fromfile:
            with open("my_instance.pkl", "rb") as file:
                self.world = pickle.load(file)
                self.world.game = self
        else:
            self.world = World(sizeX, sizeY, self)

        window_width = 800
        window_height = 600
        window_size = (window_width, window_height)
        pygame.init()
        pygame.font.init()
        pygame.display.set_caption('The Game')
        self.screen = pygame.display.set_mode(window_size)
        self.screen.fill(WHITE)
        self.font = pygame.font.SysFont("Arial", 12)
        pygame.display.flip()

    def start(self):
        running = True
        self.screen.fill(WHITE)
        self.world.garbagecollector()
        self.paintWorld()
        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    with open("my_instance.pkl", "wb") as file:
                        pickle.dump(self.world, file)
                    pygame.quit()
                    sys.exit()
                elif event.type == pygame.KEYDOWN:
                    if event.key == 13:
                        self.world.nextRound()
                        self.paintWorld()
                        self.world.garbagecollector()

    def paintText(self, text, x, y):
        logs_surface = self.font.render(text, True, BLACK)
        logs_rect = logs_surface.get_rect(center=(x,y))
        self.screen.blit(logs_surface, logs_rect)

    def paintWorld(self):
        human = None
        font = pygame.font.SysFont("Arial", 12)
        self.screen.fill(WHITE)
        for i in range(0, self.world.sizeX):
            for j in range(0, self.world.sizeY):
                pygame.draw.rect(self.screen, BLACK, (20 * i, 20 * j, 20, 20), 1)

        for org in self.world.organisms:
            pygame.draw.rect(self.screen, org.color, (20 * org.position_x, 20 * org.position_y, 20, 20), 0)
            logs_surface = font.render(org.symbol, True, BLACK)
            logs_rect = logs_surface.get_rect(center=(20 * org.position_x + 10, 20 * org.position_y + 10))
            self.screen.blit(logs_surface, logs_rect)
            if isinstance(org,Human):
                human = org

        i = 0
        for text in self.world.logs:
            logs_surface = font.render(text, True, BLACK)
            logs_rect = logs_surface.get_rect(center=(650, 50 + (i * 20)))
            self.screen.blit(logs_surface, logs_rect)
            i += 1

        if(human != None):
            self.paintText("Human GUI", 20*(self.world.sizeX+1) + 10, 10)
            if(human.isskillactive):
                self.paintText("Status umiejetnosci: AKTYWNA", 20 * (self.world.sizeX + 2) + 30, 25)
                self.paintText("Prędkość: " + str(human.speed), 20 * (self.world.sizeX + 3) + 25, 55)
                self.paintText("Pozostało użyć: " + str(human.duration), 20 * (self.world.sizeX + 3) + 25, 40)
            else:
                self.paintText("Status umiejetnosci: NIE AKTYWNA", 20 * (self.world.sizeX + 3) + 25, 25)
                self.paintText("Cooldown: " + str(human.cooldown), 20 * (self.world.sizeX + 1) + 25, 40)

        pygame.display.flip()
