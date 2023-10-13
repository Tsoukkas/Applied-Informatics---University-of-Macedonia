package com.example.r2;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.os.StrictMode;
import android.util.Log;
import android.widget.TextView;
import android.widget.Toast;


import org.w3c.dom.Text;

import java.io.IOException;

import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;




public class MainActivity extends AppCompatActivity {
    TextView check;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        getSupportActionBar().hide();
        StrictMode.enableDefaults();

        check = findViewById(R.id.connect_check);

        try {
            OkHttpClient client = new OkHttpClient();

            Request request = new Request.Builder()
                    .url("http://192.168.2.3/project/myne.php")
                    .build();

            try {
                Response response = client.newCall(request).execute();

                if (response.isSuccessful()) {
                    Toast.makeText(getApplicationContext(), "PHP MySQL CONNECT...", Toast.LENGTH_LONG).show();
                    check.setText("Success!");
                } else {
                    Toast.makeText(getApplicationContext(), "Connection failed!", Toast.LENGTH_LONG).show();
                    check.setText("Failure!");
                }

            } catch (IOException e) {
                e.printStackTrace();
                Toast.makeText(getApplicationContext(), "Connection failed!", Toast.LENGTH_LONG).show();
                check.setText("Failure!");
            }
        } catch (Exception e) {
            Log.e("Fail 1", e.toString());
            Toast.makeText(getApplicationContext(), e.toString(), Toast.LENGTH_SHORT).show();
            check.setText("Failure!");
        }

    }
}
