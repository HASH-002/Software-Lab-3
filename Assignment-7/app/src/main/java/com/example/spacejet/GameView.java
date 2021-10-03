package com.example.spacejet;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
import android.media.MediaPlayer;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import com.example.spacejet.Modals.Boom;
import com.example.spacejet.Modals.Enemy;
import com.example.spacejet.Modals.Friend;
import com.example.spacejet.Modals.Player;
import com.example.spacejet.Modals.Star;

import java.util.ArrayList;

public class GameView extends SurfaceView implements Runnable {

    //boolean variable to track if the game is playing or not
    volatile boolean playing;

    //the game thread
    private Thread gameThread = null;

    //context to be used in onTouchEvent to cause the activity transition from GameActivity to MainActivity.
    private Context context;
    
    private Player player;
    private Enemy enemy;
    private Friend friend;
    private Boom boom;
    private ArrayList<Star> stars;
    
    //These objects will be used for drawing
    private Paint paint;
    private Canvas canvas;
    private SurfaceHolder surfaceHolder;


    int screenX; //a screenX holder
    int countMisses;
    boolean flag ; //indicator that the enemy has just entered the game screen
    private boolean isGameOver ;

    // Maintaining Scores
    int score;
    int highScore[];
    SharedPreferences sharedPreferences;

    //the mediaPlayer objects to configure the background music
    static MediaPlayer gameOnSound;
    final MediaPlayer killedEnemySound;
    final MediaPlayer gameOverSound;

    public GameView(Context context, int screenX, int screenY) {
        super(context);

        this.context = context;
        player = new Player(context, screenX, screenY);
        enemy = new Enemy(context, screenX, screenY);
        boom = new Boom(context);
        friend = new Friend(context, screenX, screenY);

        //initializing drawing objects
        surfaceHolder = getHolder();
        paint = new Paint();

        stars = new ArrayList<Star>();
        int starNums = 100;
        for (int i = 0; i < starNums; i++) {
            Star s  = new Star(screenX, screenY);
            stars.add(s);
        }

        this.screenX = screenX;
        countMisses = 0;
        isGameOver = false;

        //setting the score to 0 initially
        score = 0;
        highScore = new int[4];
        sharedPreferences = context.getSharedPreferences("SHAR_PREF_NAME",Context.MODE_PRIVATE);

        //initializing the array high scores with the previous values
        highScore[0] = sharedPreferences.getInt("score1",0);
        highScore[1] = sharedPreferences.getInt("score2",0);
        highScore[2] = sharedPreferences.getInt("score3",0);
        highScore[3] = sharedPreferences.getInt("score4",0);

        //initializing the media players for the game sounds and starting the game music as the game starts
        gameOnSound = MediaPlayer.create(context,R.raw.gameon);
        killedEnemySound = MediaPlayer.create(context,R.raw.killedenemy);
        gameOverSound = MediaPlayer.create(context,R.raw.gameover);
        gameOnSound.start();
    }

    @Override
    public void run() {
        while (playing) {
            update();
            draw();
            control();
        }
    }

    private void update() {

        score++;
        player.update();

        //setting boom outside the screen
        boom.setX(-250);
        boom.setY(-250);

        // Updating the stars with player speed
        for (Star s : stars)
            s.update(player.getSpeed());

        //setting the flag true when the enemy just enters the screen
        if(enemy.getX()==screenX)
            flag = true;

        enemy.update(player.getSpeed());

        //if collision occurs with player
        if (Rect.intersects(player.getDetectCollision(), enemy.getDetectCollision())) {
            //displaying boom at that location
            boom.setX(enemy.getX());
            boom.setY(enemy.getY());

            //playing a sound at the collision between player and the enemy
            killedEnemySound.start();

            enemy.setX(-200);
        }
        // the condition where player misses the enemy
        else{

            //if the enemy has just entered
            if(flag){
                //if player's x coordinate is more than the enemy's x coordinate.i.e. enemy has just passed across the player
                if(player.getDetectCollision().exactCenterX()>=enemy.getDetectCollision().exactCenterX()){

                    //increment countMisses
                    countMisses++;

                    //setting the flag false so that the else part is executed only when new enemy enters the screen
                    flag = false;
                    //if no of Misses is equal to 3, then game is over.
                    if(countMisses==3){

                        //setting playing false to stop the game.
                        playing = false;
                        isGameOver = true;

                        //stopping the gameon music
                        gameOnSound.stop();
                        //play the game over sound
                        gameOverSound.start();

                        //Assigning the scores to the highscore integer array
                        for(int i=0;i<4;i++){
                            if(highScore[i]<score){
                                final int finalI = i;
                                highScore[i] = score;
                                break;
                            }
                        }

                        //storing the scores through shared Preferences
                        SharedPreferences.Editor e = sharedPreferences.edit();
                        for(int i=0;i<4;i++){
                            int j = i+1;
                            e.putInt("score"+j,highScore[i]);
                        }
                        e.apply();
                    }
                }
            }
        }

        //updating the friend ships coordinates
        friend.update(player.getSpeed());

        //checking for a collision between player and a friend
        if(Rect.intersects(player.getDetectCollision(),friend.getDetectCollision())){

            //displaying the boom at the collision
            boom.setX(friend.getX());
            boom.setY(friend.getY());
            //setting playing false to stop the game
            playing = false;
            //setting the isGameOver true as the game is over
            isGameOver = true;

            //stopping the gameon music
            gameOnSound.stop();
            //play the game over sound
            gameOverSound.start();

            //Assigning the scores to the highscore integer array
            for(int i=0;i<4;i++){

                if(highScore[i]<score){

                    final int finalI = i;
                    highScore[i] = score;
                    break;
                }
            }
            //storing the scores through shared Preferences
            SharedPreferences.Editor e = sharedPreferences.edit();

            for(int i=0;i<4;i++){

                int j = i+1;
                e.putInt("score"+j,highScore[i]);
            }
            e.apply();
        }
    }

    private void draw() {

        //checking if surface is valid
        if (surfaceHolder.getSurface().isValid()) {

            canvas = surfaceHolder.lockCanvas(); //locking the canvas
            canvas.drawColor(Color.BLACK); //drawing a background color for canvas

            paint.setColor(Color.WHITE); //setting the paint color to white to draw the stars

            //drawing all stars
            for (Star s : stars) {
                paint.setStrokeWidth(s.getStarWidth());
                canvas.drawPoint(s.getX(), s.getY(), paint);
            }

            //drawing the score on the game screen
            paint.setTextSize(30);
            canvas.drawText("Score:"+score,100,50,paint);

            //Drawing the player, enemy, friends and boom
            canvas.drawBitmap(player.getBitmap(), player.getX(), player.getY(), paint);
            canvas.drawBitmap(enemy.getBitmap(), enemy.getX(), enemy.getY(), paint);
            canvas.drawBitmap(boom.getBitmap(), boom.getX(), boom.getY(), paint);
            canvas.drawBitmap(friend.getBitmap(), friend.getX(), friend.getY(), paint);

            //draw game Over when the game is over
            if(isGameOver){
                paint.setTextSize(150);
                paint.setTextAlign(Paint.Align.CENTER);

                int yPos=(int) ((canvas.getHeight() / 2) - ((paint.descent() + paint.ascent()) / 2));
                canvas.drawText("Game Over",canvas.getWidth()/2,yPos,paint);
            }

            //Unlocking the canvas
            surfaceHolder.unlockCanvasAndPost(canvas);
        }
    }

    private void control() {
        try {
            gameThread.sleep(17);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public void pause() {
        playing = false;
        try {
            gameThread.join();
        } catch (InterruptedException e) {
        }
    }

    public void resume() {
        playing = true;
        gameThread = new Thread(this);
        gameThread.start();
    }

    // Movement of Space jet game
    @Override
    public boolean onTouchEvent(MotionEvent motionEvent) {
        switch (motionEvent.getAction() & MotionEvent.ACTION_MASK) {
            case MotionEvent.ACTION_UP: //stopping the boosting when screen is released
                player.stopBoosting();
                break;
            case MotionEvent.ACTION_DOWN: //boosting the space jet when screen is pressed
                player.setBoosting();
                break;
        }

        //Tapping on gameOver screen sends you to MainActivity
        if(isGameOver){
            if(motionEvent.getAction()==MotionEvent.ACTION_DOWN)
                context.startActivity(new Intent(context,MainActivity.class));
        }
        return true;
    }

    //stop the music on exit
    public static void stopMusic(){
        gameOnSound.stop();
    }
}