package com.example.r2v2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
  Button btn;
  String myIP = "192.168.2.3" ;
  EditText id_provision,proname,prodescription,cost;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        btn = findViewById(R.id.button);

        id_provision = findViewById(R.id.Code_text);
        proname = findViewById(R.id.name_text);
        prodescription = findViewById(R.id.textInputEditText2);
        cost = findViewById(R.id.textInputEditText);

        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                String url= "http://"+myIP+"/project/myfile.php?code=" + id_provision.getText() +
                        "&name=" + proname.getText() + "&description=" + prodescription.getText() + "&cost=" + cost.getText();
                try {
                    OkhttpHandler okHttpHandler = new OkhttpHandler();
                    okHttpHandler.createProvision(url);
                    Toast.makeText(getApplicationContext(), "Data inserted !",
                            Toast.LENGTH_SHORT).show();
                } catch (Exception e) {
                    e.printStackTrace();
                }

            }
        });
    }
}