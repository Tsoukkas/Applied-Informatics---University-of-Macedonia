package com.example.footballselection;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;

import com.squareup.picasso.Picasso;

import java.util.ArrayList;

public class MainActivity2 extends AppCompatActivity {
    Button button3;
    ImageView img;
    PlayersList playersList = new PlayersList();
    ArrayList<String> ikones = new ArrayList<>();
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        button3 = findViewById(R.id.button3);
        img = findViewById(R.id.imageView);
        button3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity2.this,MainActivity.class);
                startActivity(intent);
            }
        });
        Intent intent = getIntent();
        String selectedRadioButtonText = intent.getStringExtra("selectedRadioButtonText");
        String type1 = intent.getStringExtra("selectedSpinnerItem");
        ikones = playersList.getImages(type1);
        String imageUrl = getProfile(ikones,selectedRadioButtonText);

         img = findViewById(R.id.imageView);

        Picasso.get().load(imageUrl).into(img);
    }
    public String getProfile(ArrayList<String> lista,String checked){
        String ikona = "";
        for(int i=0;i<lista.size();i++){
                ikona = lista.get(i);
            }
        return ikona ;
    }

}