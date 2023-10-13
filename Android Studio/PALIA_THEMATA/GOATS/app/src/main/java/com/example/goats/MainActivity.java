package com.example.goats;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;

import android.view.View;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.RadioGroup;

import java.util.ArrayList;


public class MainActivity extends AppCompatActivity {
    RadioGroup rg;
    Button btn;
    ArrayList<String> lista_onomaton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        rg = findViewById(R.id.rg);
        btn =findViewById(R.id.btn);
        GoatList a = new GoatList();
        lista_onomaton = a.getNames();
        displayNames();
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this,MainActivity2.class);
                int selected_rb = rg.getCheckedRadioButtonId();
                RadioButton selectedRadioButton = findViewById(selected_rb);
                String selectedRadioButtonText = selectedRadioButton.getText().toString();
                intent.putExtra("selectedRadioButtonText", selectedRadioButtonText);
                startActivity(intent);
            }
        });
    }

    public void displayNames(){
        for(int i=0;i<lista_onomaton.size();i++){
            RadioButton rb = new RadioButton(this);
            rb.setText(lista_onomaton.get(i));
            rb.setId(100+i);
            rg.addView(rb);
        }
    }
}