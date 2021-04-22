from pygame import *
import random

ballpic = image.load('ball.png')
ballpic.set_colorkey((0, 0, 0))

numballs = 7
delay = 7
mark = 55

done = False

balls = []
x = []
y = []


for count in range(numballs):
	balls.append(dict)
	balls[count] = { 
						'x': random.randint(1, 700), 
						'y': random.randint(1, 480),
						'xmove': int(random.choice([-3, -2, -1, 1, 2, 3])),
						'ymove': int(random.choice([-3, -2, -1, 1, 2, 3])),
						'mark': 0 
					}

init()
screen = display.set_mode((800, 540))
display.set_caption('Ball game')
event.set_grab(1)

while done == False:
	screen.fill(0)

	for count in range(numballs):
		screen.blit(ballpic, (balls[count]['x'], balls[count]['y']))

	display.update()

	time.delay(delay)

	for count in range(numballs):
		
		x1 = balls[count]['x']
		x.append(x1)
		y1 = balls[count]['y']
		y.append(y1)
		

		balls[count]['x'] = balls[count]['x'] + balls[count]['xmove']
		balls[count]['y'] = balls[count]['y'] + balls[count]['ymove']

	
	ctr = 0

	for count in range(numballs):
		
		for cnt in range(count + 1, numballs):
			
			#print "%d  -> %d" % (count, cnt)
			
			if balls[cnt]['mark'] <= 0 and balls[count]['mark'] <= 0:
				if (( abs(balls[count]['x'] - balls[cnt]['x']) <= 16 )
						and 
							( abs(balls[count]['y'] - balls[cnt]['y']) <= 16 )):


					if balls[count]['xmove'] * balls[cnt]['xmove'] < 0:

						balls[count]['xmove'] = -balls[count]['xmove']

						balls[cnt]['xmove'] = -balls[cnt]['xmove']


					elif balls[count]['xmove'] * balls[cnt]['xmove'] == 0:

						if balls[count]['xmove'] == 0:
							balls[count]['xmove'] = balls[cnt]['xmove']

						else:
							balls[cnt]['xmove'] = balls[count]['xmove']
						

					if balls[count]['ymove'] * balls[cnt]['ymove'] < 0:

							balls[count]['ymove'] = -balls[count]['ymove']

							balls[cnt]['ymove'] = -balls[cnt]['ymove']


					elif balls[count]['ymove'] * balls[cnt]['ymove'] == 0:

						if balls[count]['ymove'] == 0:

							balls[count]['ymove'] = balls[cnt]['ymove']

						else:

							balls[cnt]['ymove'] = balls[count]['ymove']


					#print balls[count]['mark']					

					#balls[count]['mark'] = mark/3

					#print balls[cnt]['mark']

					#balls[cnt]['mark'] = mark/2


			balls[cnt]['mark'] -= 1


		if balls[count]['x'] > 770:
			balls[count]['xmove'] = random.randint(-3, -1) #right
			ctr = 1

		if balls[count]['x'] < 0:
			balls[count]['xmove'] = random.randint(1, 3) #left
			ctr = 2

		if balls[count]['y'] > 510:
			balls[count]['ymove'] = random.randint(-3, -1) #down
			ctr = 3

		if balls[count]['y'] < 0:
			balls[count]['ymove'] = random.randint(1, 3) #up
			ctr = 4

		balls[count]['mark'] -= 1

		if ctr and numballs < 200 :

			if balls[count]['mark'] <= 0 :
			
				p = random.randint(0, 6)
				
				print p

				if p == 0:			   	#on/off

					balls.append(dict)
					if ctr == 1: 
						balls[numballs] = { 'x': balls[count]['x'],
						 					'y': balls[count]['y'], 
						 					'xmove': balls[count]['xmove'], 
						 					'ymove': -balls[count]['ymove'], 
						 					'mark': mark }

					elif ctr == 2: 
						balls[numballs] = { 'x': balls[count]['x'], 
											'y': balls[count]['y'], 
											'xmove': balls[count]['xmove'], 
											'ymove': -balls[count]['ymove'], 
											'mark': mark }
						
					elif ctr == 3: 
						balls[numballs] = { 'x': balls[count]['x'], 
											'y': balls[count]['y'], 
											'xmove': -balls[count]['xmove'], 
											'ymove': balls[count]['ymove'], 
											'mark': mark }
					
					elif ctr == 4: 
						balls[numballs] = { 'x': balls[count]['x'], 
											'y': balls[count]['y'], 
											'xmove': -balls[count]['xmove'], 
											'ymove': balls[count]['ymove'], 
											'mark': mark }

					numballs += 1

				balls[count]['mark'] = mark
			
			ctr = 0 

	for e in event.get():
		if e.type == KEYUP:
			if e.key == K_ESCAPE:
				done = True

	if screen.get_at((mouse.get_pos())) == (255, 255, 255, 255):
		done = True

print "You lasted for", time.get_ticks()/1000, "seconds!"


