package com.example.spacejet;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.widget.TextView;

public class HighScore extends AppCompatActivity {

    TextView score1,score2,score3,score4;
    SharedPreferences sharedPreferences;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_high_score);

        score1 = findViewById(R.id.textView);
        score2 = findViewById(R.id.textView2);
        score3 = findViewById(R.id.textView3);
        score4 = findViewById(R.id.textView4);

        // setting sharedPreferences
        sharedPreferences  = getSharedPreferences("SHAR_PREF_NAME", Context.MODE_PRIVATE);

        //setting the values to the textViews
        score1.setText("1."+sharedPreferences.getInt("score1",0));
        score2.setText("2."+sharedPreferences.getInt("score2",0));
        score3.setText("3."+sharedPreferences.getInt("score3",0));
        score4.setText("4."+sharedPreferences.getInt("score4",0));
    }
}