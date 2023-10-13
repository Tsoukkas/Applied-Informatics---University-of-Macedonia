package com.example.a2022_animals;

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
 AnimalList a ;
 ArrayList<String> types = a.getTypes();
  String tipos= "";
  ArrayList<String> names = a.getNames();
     ArrayList<String>  voices= a.getVoices();
     ArrayList<String> urls = a.getUrls();
    String foni = "";
    String selectedAnimal = getIntent().getStringExtra("selectedAnimal");
    ImageView img ;
    Button btn ;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        txt = findViewById(R.id.txt);
        img = findViewById(R.id.img);
        btn = findViewById(R.id.btn1);
        tipos = getTipos();
        foni = getVoice();
        txt.setText("My name is: " +selectedAnimal+", I am a "+tipos+" and I "+ foni);
        String imageUrl = geturl();
        Picasso.get().load(imageUrl).into(img);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity2.this, MainActivity.class);
                startActivity(intent);
            }
        });
    }

    public String geturl(){
        String a="";
        for(int i =0;i< urls.size();i++){
            if(selectedAnimal.equals(names.get(i))){
                a=urls.get(i);
            }
        }
        return a;
    }

    public String getTipos(){
        String a="";
        for(int i =0;i< types.size();i++){
            if(selectedAnimal.equals(names.get(i))){
                a=types.get(i);
            }
        }
        return a;
    }
    public String getVoice(){
        String a="";
        for(int i =0;i< voices.size();i++){
            if(selectedAnimal.equals(names.get(i))){
                a=voices.get(i);
            }
        }
        return a;
    }

}