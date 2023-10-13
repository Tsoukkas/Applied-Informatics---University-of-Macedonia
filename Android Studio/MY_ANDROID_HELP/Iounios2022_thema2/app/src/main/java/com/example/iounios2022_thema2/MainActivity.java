package com.example.iounios2022_thema2;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import java.io.IOException;
import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    RadioGroup rg ;
    Button btn;
    CityList cl = new CityList();
    ArrayList<String> onomata = new ArrayList<>();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        onomata = cl.getNames();
        displayCities(onomata);
        btn = findViewById(R.id.btn);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int selectedRadioButtonId = rg.getCheckedRadioButtonId();
                RadioButton selectedRadioButton = findViewById(selectedRadioButtonId);
                String selectedRadioButtonText = selectedRadioButton.getText().toString();
                Intent intent = new Intent(MainActivity.this, SecondActivity.class);
                intent.putExtra("selectedRadioButtonText", selectedRadioButtonText);
                startActivity(intent);
            }
        });
    }

    public void displayCities(ArrayList<String> cities) {
        rg = findViewById(R.id.rg);
        for (int i=0;i<cities.size();i++) {
            RadioButton rb = new RadioButton(this);
            rb.setText(cities.get(i).toString());
            rb.setId(100+i);
            rg.addView(rb);
        }

    }


}


