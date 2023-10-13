package com.example.a2022_againclubs;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import com.squareup.picasso.Picasso;

import java.util.ArrayList;

public class MainActivity2 extends AppCompatActivity {
    TextView txt;
    ImageView img;
     StadiumList sl = new StadiumList();
     ArrayList<Stadium> info = sl.lista;
     Button btn ;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        Intent intent = getIntent();
        String selectedRadioButtonText = intent.getStringExtra("selectedRadioButtonText");
        txt = findViewById(R.id.txt);
        img = findViewById(R.id.img);
       String club,image,chant ;
       club = getClub(selectedRadioButtonText);
       image = getImage(selectedRadioButtonText);
       chant = getFan_Chant(selectedRadioButtonText);
       txt.setText("The fans of: "+selectedRadioButtonText+"were all night singing the "+chant+"authem in "+club+".");
        Picasso.get().load(image).into(img);
        btn = findViewById(R.id.button);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity2.this,MainActivity.class);
                startActivity(intent);
            }
        });
    }
    public String getClub(String a){
        String club ="";
        for(int i=0;i<info.size();i++){
            if(a.equals(info.get(i).getName())){
                club = info.get(i).getClub();
            }
        }
        return club;
    }

    public String getFan_Chant(String a){
        String chant ="";
        for(int i=0;i<info.size();i++){
            if(a.equals(info.get(i).getName())){
                chant = info.get(i).getFan_chant();
            }
        }
        return chant;
    }

    public String getImage(String a){
        String image ="";
        for(int i=0;i<info.size();i++){
            if(a.equals(info.get(i).getName())){
                image = info.get(i).getImage();
            }
        }
        return image;
    }
}