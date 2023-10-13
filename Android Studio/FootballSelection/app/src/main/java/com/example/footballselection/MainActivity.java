package com.example.footballselection;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Spinner;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {
    ArrayList<String> cblist = new ArrayList<>();
    RadioGroup rg;
    PlayersList a = new PlayersList();
    Button button, button1;
    Spinner spinner;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        button = findViewById(R.id.button);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                onClickPickPlayer();
            }
        });
        button1 = findViewById(R.id.button2);
        button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int selectedRadioButtonId = rg.getCheckedRadioButtonId();
                RadioButton selectedRadioButton = findViewById(selectedRadioButtonId);
                String selectedRadioButtonText = selectedRadioButton.getText().toString();
                String selectedSpinnerItem = spinner.getSelectedItem().toString();

                Intent intent = new Intent(MainActivity.this, MainActivity2.class);
                intent.putExtra("selectedRadioButtonText", selectedRadioButtonText);
                intent.putExtra("selectedSpinnerItem", selectedSpinnerItem);
                startActivity(intent);
            }
        });
    }

    private void createRadioButtons(RadioGroup rg, List<String> PlayersList) {
        int size = PlayersList.size();
        final RadioButton[] rb = new RadioButton[size];
        for (int i = 0; i < size; i++) {
            rb[i] = new RadioButton(this);
            rb[i].setText(" " + PlayersList.get(i));
            rb[i].setId(i + 100);
            rg.addView(rb[i]);
        }
    }

    public void onClickPickPlayer() {
        spinner = findViewById(R.id.spinner);
        String type = spinner.getSelectedItem().toString();
        ArrayList<String> PlayersList = a.getNames(type);
        rg = findViewById(R.id.rg);

        rg.removeAllViews();

        if (PlayersList.size() == 0) {
            Toast.makeText(MainActivity.this, type, Toast.LENGTH_SHORT).show();
        } else {
            rg.setOrientation(RadioGroup.VERTICAL);
            createRadioButtons(rg, PlayersList);
            rg.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(RadioGroup group, int checkedId) {
                    RadioButton rb = findViewById(checkedId);
                    Toast.makeText(MainActivity.this, type, Toast.LENGTH_SHORT).show();
                }
            });
        }
    }
}
