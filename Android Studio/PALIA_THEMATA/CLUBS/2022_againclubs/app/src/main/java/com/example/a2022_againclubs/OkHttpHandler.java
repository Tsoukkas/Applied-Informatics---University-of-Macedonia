package com.example.a2022_againclubs;

import android.os.StrictMode;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.Iterator;

import okhttp3.MediaType;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.RequestBody;
import okhttp3.Response;

public class OkHttpHandler {

    public OkHttpHandler() {
        StrictMode.ThreadPolicy policy = new
                StrictMode.ThreadPolicy.Builder().permitAll().build();
        StrictMode.setThreadPolicy(policy);
    }

    ArrayList<Stadium> getClubs(String url) throws Exception {
        ArrayList<Stadium> clubs = new ArrayList<>();
        OkHttpClient client = new OkHttpClient().newBuilder().build();
        RequestBody body = RequestBody.create("",
                MediaType.parse("text/plain"));
        Request request = new Request.Builder().url(url).method("POST",
                body).build();
        Response response = client.newCall(request).execute();
        String data = response.body().string();
        //System.out.println("My Response: " + data);
        try {
            JSONObject json = new JSONObject(data);
            Iterator<String> keys = json.keys();
            while (keys.hasNext()) {
                String key = keys.next();
                JSONObject item =json.getJSONObject(key);
                String club = item.getString("club").toString();
                String name = item.getString("name").toString();
                String fan_chant = item.getString("fan_chant").toString();
                String image = item.getString("image").toString();
                clubs.add(new Stadium(club,name,fan_chant,image));
            }
        } catch (JSONException e) {
            e.printStackTrace();
        }
        return clubs;
    }
}