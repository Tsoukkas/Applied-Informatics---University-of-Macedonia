package com.example.a2022_animals;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.RadioGroup;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    //Button btn;
    //TextView txt;
    // btn = findViewById(R.id.btn);
    //  txt = findViewById(R.id.txt);

    //  btn.setOnClickListener(new View.OnClickListener() {
    //     @Override
    //     public void onClick(View v) {
    //       String name = "andonis";
    //       txt.setText(txt.getText() + name);
    //    }
    //   });
    RadioGroup rg;
    Button btn;
    AnimalList a = new AnimalList();
    ArrayList<String> lista = a.getNames();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        createRadioButtons();
        btn = findViewById(R.id.btn);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int selectedId = rg.getCheckedRadioButtonId();
                RadioButton radioButton = findViewById(selectedId);
                String selectedAnimal = radioButton.getText().toString();

                Intent intent = new Intent(MainActivity.this, MainActivity2.class);
                intent.putExtra("selectedAnimal", selectedAnimal);
                startActivity(intent);
            }

        });
    }
    public void createRadioButtons(){
        rg = findViewById(R.id.rg);

        for(int i=0;i<lista.size();i++){
            RadioButton rb = new RadioButton(this);
            rb.setText(lista.get(i));
            rb.setId(100+i);
            rg.addView(rb);
        }
    }

}