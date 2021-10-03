package com.example.spacejet.Modals;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Rect;

import com.example.spacejet.R;

public class Player {
    //Bitmap to get character from image
    private Bitmap bitmap;

    //coordinates
    private int x;
    private int y;

    //motion speed of the character
    private int speed = 0;

    //boolean variable to track the ship is boosting or not
    private boolean boosting;

    //Gravity Value to add gravity effect on the ship
    private final int GRAVITY = -10;

    // Y coordinates of the ship
    private int maxY;
    private int minY;

    //Limit the bounds of the ship's speed
    private final int MIN_SPEED = 1;
    private final int MAX_SPEED = 20;

    //creating a rect object
    private Rect detectCollision;

    //constructor
    public Player(Context context, int screenX, int screenY) {
        x = 75;
        y = 50;
        speed = 1;
        bitmap = BitmapFactory.decodeResource(context.getResources(), R.drawable.player);

        maxY = screenY - bitmap.getHeight(); //calculating maxY
        minY = 0; //top edge's y point is 0 so min y will always be zero
        boosting = false; //setting the boosting value to false initially

        //initializing rect object
        detectCollision = new Rect(x, y, bitmap.getWidth(), bitmap.getHeight());
    }

    public void setBoosting() {
        boosting = true;
    }
    public void stopBoosting() {
        boosting = false;
    }

    // Method to update coordinate of character
    public void update() {
        // Managing speed of ship
        if (boosting)
            speed += 2;
        else
            speed -= 5;

        //controlling the speed limits
        if (speed > MAX_SPEED)
            speed = MAX_SPEED;
        if (speed < MIN_SPEED)
            speed = MIN_SPEED;

        // moving the ship down
        y -= speed + GRAVITY;

        // Managing Screen limit for the ships
        if (y < minY)
            y = minY;
        if (y > maxY)
            y = maxY;

        //adding top, left, bottom and right to the rect object
        detectCollision.left = x;
        detectCollision.top = y;
        detectCollision.right = x + bitmap.getWidth();
        detectCollision.bottom = y + bitmap.getHeight();
    }

    // Getters and Setters
    public Rect getDetectCollision() {
        return detectCollision;
    }

    public Bitmap getBitmap() {
        return bitmap;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getSpeed() {
        return speed;
    }
}
