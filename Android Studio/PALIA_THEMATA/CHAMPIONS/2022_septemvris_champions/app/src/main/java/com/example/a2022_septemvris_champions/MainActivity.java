package com.example.a2022_septemvris_champions;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import com.squareup.picasso.Picasso;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    RadioGroup rg;
    OkHttpHandler ok;
    ClubsList listItem = new ClubsList();
    ArrayList<String> cl = new ArrayList<>();
    Button btn ;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        rg = findViewById(R.id.rg);
        cl = listItem.getYears();
        displayYears(cl);
    }
    public void displayYears(ArrayList<String> cl){

        for(int i=0;i< cl.size();i++){
            RadioButton rb = new RadioButton(this);
            rb.setText(cl.get(i));
            rb.setId(100+i);
            rg.addView(rb);
        }
       btn = findViewById(R.id.btn);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                btn = findViewById(R.id.btn);
                btn.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        int selectedRadioButtonId = rg.getCheckedRadioButtonId();
                        if (selectedRadioButtonId != -1) {
                            RadioButton selectedRadioButton = findViewById(selectedRadioButtonId);
                            String selectedYear = selectedRadioButton.getText().toString();

                            // Εκτελέστε τις ενέργειες που θέλετε όταν πατηθεί το κουμπί με βάση το επιλεγμένο RadioButton
                            String omada = listItem.getName(selectedYear);
                            Toast.makeText(MainActivity.this, omada, Toast.LENGTH_SHORT).show();
                            String imageUrl = listItem.getUrl(selectedYear);
                            ImageView imageView = findViewById(R.id.imageView); // Αντικαταστήστε το imageView με το ID του ImageView σας
                            Picasso.get().load(imageUrl).into(imageView);
                        } else {
                            // Ο χρήστης δεν έχει επιλέξει RadioButton
                            Toast.makeText(MainActivity.this, "Παρακαλώ επιλέξτε ένα έτος", Toast.LENGTH_SHORT).show();
                        }
                    }
                });

            }
        });


    }
   /*rg.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
        @Override
        public void onCheckedChanged(RadioGroup group, int checkedId) {
            String omada ="";
            RadioButton selectedRadioButton = findViewById(checkedId);
            String selectedYear = selectedRadioButton.getText().toString();
            omada = listItem.getName(selectedYear);
            Toast.makeText(MainActivity.this, omada, Toast.LENGTH_SHORT).show();
            String imageUrl = listItem.getUrl(selectedYear);
            ImageView imageView = findViewById(R.id.imageView); // Αντικαταστήστε το imageView με το ID του ImageView σας
            Picasso.get().load(imageUrl).into(imageView);

        }
    });*/

}