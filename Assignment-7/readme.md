# Assignment 7 - Android Development

## Space Jet Game
* Jet has to kill the enemies by hitting them.
* Jet shouldn't kill the Friends.
* 3 misses of killing the enemy leads to Game Over.
* High Score is mainitained.
* Sounds are added.

## Android Studio
Android studio was used for Android application development for the SpaceJet game.
Java runtime environment and JDK is required as we used Java as the programming language.

The fundamental components of android app are: 
* Activity: An activity is a class that represents a single screen. It is like a Frame in AWT.
* View: A view is the UI element such as button, label, text field etc. Anything that you see is a view.
* Service: is a background process that can run for a long time. There are two types of services local and remote. 
*Fragment: They are like parts of activity. An activity can display one or more fragments on the screen at the same time.
* Content Providers:are used to share data between the applications.
* Intent: Intent is used to invoke components. It is mainly used to:
Start the service
Launch an activity
Display a web page
Display a list of contacts
Broadcast a message
Dial a phone call etc.
* AndroidManifest.xml: It contains information about activities, content providers, permissions etc. It is like the web.xml file in Java.
* Android Virtual Device (AVD) :It is used to test the android application without the need for mobile or tablet etc. It can be created in different configurations to emulate different types of real devices.


## Code Files

### Modals
Modals folder contains five different java game files as Boom, Friend, Enemy, PLayer and Star. 

#### Boom
We get the coordinates where our ship crashes with either friend or enemy. Also, the boom image is to be rendered at the place of crash which we do using bitmap.
Member methods:
```bash
Boom() 
setX()
setY() 
```
Constructor that initializes the image out of the screen and Setters that set the position of the image

#### Enemy
In the game, we need to generate enemies. We do that by generating random coordinates and placing the enemy image on the main activity. We also have the detect collision in case our ship crashes with the enemy. We do that using Rect and get the coordinates. We check if the coordinates of our ship and enemy lies in each other boundaries. If so, we return 
collision detected with speed.
Member methods:
```bash
Enemy()
update()
setX()
setY()
getX()
getY() 
```
Constructor that initializes the enemy at a random position on the screen with a random speed. Update function updates the speed of the enemy ship. Setter and Getters for the positions of the image.

#### Friend
Similar to enemy, we need to generate the friend ship which we do by generating the random coordinates and place the friend image on the main activity. We detect collision using 
Rect and get the coordinates. We check if the coordinates of our ship and enemy lies in each other boundaries. If so, we return collision detected. Member methods :
```bash
Friend()
update() 
setX()
setY()
getX()
getY()
```
Constructor that initializes the friend at a random position on the screen with a random speed. Update function updates the speed of the friend ship. Setter and Getters for the positions of the image.

#### Player
We start our ship at a speed of 1 and at coordinates (75, 50) and based on the player's taps, we increase or decrease the speed and change the coordinates. We also try to detect if 
our ship collides with a friend ship or enemy.
```bash
Player()
update() 
setBoosting()
stopBoosting() 
getX()
getY()
getSpeed()
```
Constructor that initializes the friend at a fixed position on the screen with a fixed speed.  Update function updates the speed of the friend ship. Getters for the positions of the image and speed of the ship. Set and Stop Boosting to change boosting to true or false.

#### Star
We try to make the background stars of the game more lively by giving it an infinte scrolling background effect. The speed of the moving stars change with change in speed of the 
ship. Member methods:
```bash
Star() 
update() 
getX()
getY() 
```
Constructor initialises the star background. Update function updates the speed of the background according to the speed of player ship, also giving infinite background effect. Getters for getting the position of the star

### MainActivity
The first screen to appear when the user launches the app. The main activity code is a Java file MainActivity.java. This is the actual application file which ultimately gets converted to a Dalvik executable and runs your application. 

class MainActivity has member methods:

```bash
onCreate(Bundle savedInstanceState)
```
Has buttons for Play and High Score and event listeners for the buttons.

```bash
onBackPressed()
```
Pops up an alert on back press.

### GameView
Modals are imported namely : Player, Enemy, Friend, Boom, ArrayList of Stars\
Paint, Canvas and SurfaceHolder are objects used for drawing\
Array of HighScore is maintained to stor the scored of each game.\
The whole functionality of the game is in this file GameView.\
class GameView has datamembers:\
```bash
volatile boolean playing;
private Thread gameThread = null;
private Context context;
private Player player;
private Enemy enemy;
private Friend friend;
private Boom boom;
private ArrayList<Star> stars;
private Paint paint;
private Canvas canvas;
private SurfaceHolder surfaceHolder;
int screenX;
int countMisses;
boolean flag; 
private boolean isGameOver;
int score;
Integer highScore[];
SharedPreferences sharedPreferences;
static MediaPlayer gameOnSound;
final MediaPlayer killedEnemySound;
final MediaPlayer gameOverSound;
```
Member methods :
```bash
GameView() 
```
Constructor creates an instance of Player, Enemy, Boom and Friend. All initialises drawing objects for the screen. Initialises high scores and media players for the sounds.
```bash
run() 
```
Updates, draws and controls while playing.
```bash
update()
```
Updates the stars with player speed. Checks for collisions and displaying boom at that location and plays a sound at the collision between player and the enemy. Check if missed enemy and does the appropriate functionality. Checks for collision between friend, add sound and boom and ends game and updates highscores array.
```bash
draw()
``` 
displays screen and texts on the screen.
```bash
pause() 
resume()
```
Pauses and resumes the game.
```bash
onTouchEvent(MotionEvent motionEvent)
```
Movement of Space jet game, boosts the spacejet when screen is pressed.
```bash
stopMusic()
```
Stops the music on exit.


### GameActivity
This is where we put it all together. Using click listener, we increase or decrease the speed of our ship and accordingly change the position of the ship based on the speed.\
class GameActivity has datamember : 
```bash
private GameView gameView       
```
Member Methods : 
```bash
onCreate(Bundle savedInstanceState) 
``` 
Gets display object and the screen resolution into point objec and initializes gameView object with screen size to the GameView constructor
```bash
onPause()
```
Pauses the game when activity is paused
```bash
onResume()
```
Runs the game when activity is resumed
```bash
onBackPressed()
``` 
Pops up an alert on back press.

### HighScore
We check for current score and update the high scores for the game.
class HighScore has the datamembers:\
TextView score1,score2,score3,score4;\
SharedPreferences sharedPreferences;\
Member method:
```bash
onCreate(Bundle savedInstanceState)
```
Displays top 4 high scores.


## Authors
- [@Hasan Koser](https://www.github.com/HASH-002)
- [@Saurav Kalsoor](https://github.com/saurav-kalsoor)
- [@Harshini Pillarisetti](https://github.com/Harshi194)
- [@AdityaKhanke](https://github.com/adityakhanke)