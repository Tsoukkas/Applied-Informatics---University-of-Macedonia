package com.example.iounios2022_thema2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import com.squareup.picasso.Picasso;

import java.util.ArrayList;

public class SecondActivity extends AppCompatActivity {
    TextView txt;

    CityList ct = new CityList();
    String mnimio = "";
    String xora = "";
    String ikona = "";
    Button btn ;
    ImageView img ;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);
        txt = findViewById(R.id.txt);
        btn = findViewById(R.id.button);
      btn.setOnClickListener(new View.OnClickListener() {
          @Override
          public void onClick(View v) {
              Intent intent = new Intent(SecondActivity.this, MainActivity.class);
              startActivity(intent);
          }
      });
        Intent intent = getIntent();
        String selectedRadioButtonText = intent.getStringExtra("selectedRadioButtonText");
        mnimio = monument(selectedRadioButtonText);
        xora = Country(selectedRadioButtonText);
        ikona = Image(selectedRadioButtonText);

        txt.setText("Thousands of visitors have visited "+ mnimio + " , in " + " "+selectedRadioButtonText + "("+xora+") , this year.");

        img = findViewById(R.id.imageView); // Αντικείμενο ImageView στο οποίο θέλετε να εμφανίσετε την εικόνα

        Picasso.get().load(ikona).into(img); // Φορτώνει την εικόνα από το URL και την εμφανίζει στο ImageView


    }
    public String monument(String onoma){
        String mnimio = "" ;
        for(int i=0;i<ct.list.size();i++){
            if(onoma.equals(ct.list.get(i).name)){
                mnimio =  ct.list.get(i).monument ;
            }
        }
        return mnimio ;
    }

    public String Country(String onoma){
        String xora = "" ;
        for(int i=0;i<ct.list.size();i++){
            if(onoma.equals(ct.list.get(i).name)){
                xora =  ct.list.get(i).country ;
            }
        }
        return xora ;
    }

    public String Image(String onoma){
        String ikona = "" ;
        for(int i=0;i<ct.list.size();i++){
            if(onoma.equals(ct.list.get(i).name)){
                ikona =  ct.list.get(i).image ;
            }
        }
        return ikona ;
    }
}