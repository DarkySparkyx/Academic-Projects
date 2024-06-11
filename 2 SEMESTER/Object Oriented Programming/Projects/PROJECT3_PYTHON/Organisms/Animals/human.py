import sys
import random

import pygame

from Organisms.Animals.animal import Animal


class Human(Animal):
    def __init__(self, position_x, position_y, world):
        super().__init__(position_x, position_y, "Human", 'H', 5, 4, world, 1, (255,20,147))
        self.isskillactive = False
        self.cooldown = 0
        self.duration = 0


    def getchild(self, newposition):
        return Human(newposition[0], newposition[1], self.world)

    def action(self):
        self.world.game.paintWorld()
        x=0
        y=0
        print("waiting for input" + self.tostring())
        running = True
        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    sys.exit()
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_LEFT:
                        x = -1
                        if self.world.ispositiongood(self.position_x + x, self.position_y + y):
                            running = False
                        else:
                            x=0
                            y=0
                    if event.key == pygame.K_RIGHT:
                        x = 1
                        if self.world.ispositiongood(self.position_x + x, self.position_y + y):
                            running = False
                        else:
                            x = 0
                            y = 0
                    if event.key == pygame.K_UP:
                        y = -1
                        if self.world.ispositiongood(self.position_x + x, self.position_y + y):
                            running = False
                        else:
                            x = 0
                            y = 0
                    if event.key == pygame.K_DOWN:
                        y = 1
                        if self.world.ispositiongood(self.position_x + x, self.position_y + y):
                            running = False
                        else:
                            x = 0
                            y = 0
                    if event.key == pygame.K_r:
                        if(self.cooldown == 0):
                            self.isskillactive = True
                            self.speed = 2
                            self.cooldown = 6
                            self.duration = 5
                            self.world.game.paintWorld()

        x = x * self.speed
        y = y * self.speed
        newx, newy = self.position_x+x, self.position_y+y

        if self.world.isplacetaken(newx, newy):
            ofiara = self.world.findorganismbyposition(newx, newy)
            ofiara.collision(self)
        else:
            self.world.logs.append(self.tostring() + " skacze na " + str(newx) + " " + str(newy))
            self.position_x = newx
            self.position_y = newy

        if(self.duration<=1):
            self.isskillactive = False
            if(self.cooldown>0):
                self.cooldown -= 1
        else:
            if(self.duration > 2):
                self.isskillactive = True
            else:
                i = random.randint(0,1)
                if(i==1):
                    self.speed = 2
                else:
                    self.speed = 1
            self.duration -= 1




