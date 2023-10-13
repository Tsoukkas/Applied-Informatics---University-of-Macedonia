package com.example.iounios2022_thema2;

import android.os.AsyncTask;
import android.os.StrictMode;

import org.json.JSONException;
import org.json.JSONObject;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;

import okhttp3.*;

public class OkHttpHandler {
    public OkHttpHandler() {
        StrictMode.ThreadPolicy policy = new
                StrictMode.ThreadPolicy.Builder().permitAll().build();
        StrictMode.setThreadPolicy(policy);
    }

    ArrayList<city> getCities(String url) throws IOException {
        ArrayList<city> polis = new ArrayList<city>() ;
        OkHttpClient client = new OkHttpClient().newBuilder().build();
        RequestBody body = RequestBody.create("",
                MediaType.parse("text/plain"));
        Request request = new Request.Builder().url(url).method("POST",
                body).build();
        Response response = client.newCall(request).execute();
        String data = response.body().string();
        System.out.println("My response: "+ response);
        try {
            JSONObject json = new JSONObject(data);
            Iterator<String> keys = json.keys();
            while (keys.hasNext()) {
                String key = keys.next();
                JSONObject item = json.getJSONObject(key);
                String name = item.getString("name").toString();
                String monument = item.getString("monument").toString();
                String country = item.getString("country").toString();
                String image = item.getString("image").toString();
                polis.add(new city(name,monument,country,image));
            }
        } catch (JSONException e) {
            e.printStackTrace();
        }

        return polis;
    }

}
