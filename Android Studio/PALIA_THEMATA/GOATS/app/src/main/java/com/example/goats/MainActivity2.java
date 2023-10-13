package com.example.goats;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import com.squareup.picasso.Picasso;

import java.util.ArrayList;
import java.util.List;

public class MainActivity2 extends AppCompatActivity {
    TextView txt;
    ImageView img;
    GoatList sl = new GoatList();
    ArrayList<Goat> info = sl.lista;
    Button btn ;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        Intent intent = getIntent();
        String selectedRadioButtonText = intent.getStringExtra("selectedRadioButtonText");
        txt = findViewById(R.id.txt);
        img = findViewById(R.id.img);
        String image,name ;
        Integer tr,total ;
         total = getTotal(selectedRadioButtonText);
        image = getImage(selectedRadioButtonText);
        tr = getTr(selectedRadioButtonText);
        txt.setText(selectedRadioButtonText + " has " + total +" G/A "+ " and "+ tr +" trophies .");
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
    public Integer getTotal(String a){
        Integer tl = 0;
        for(int i=0;i<info.size();i++){
            if(a.equals(info.get(i).getName())){
                tl = info.get(i).totalGA;
            }
        }
        return tl;
    }

    public Integer getTr(String a){
        Integer tr = 0;
        for(int i=0;i<info.size();i++){
            if(a.equals(info.get(i).getName())){
                tr = info.get(i).tr;
            }
        }
        return tr;
    }

    public String getImage(String a){
        String image ="";
        for(int i=0;i<info.size();i++){
            if(a.equals(info.get(i).getName())){
                image = info.get(i).image;
            }
        }
        return image;
    }
}
