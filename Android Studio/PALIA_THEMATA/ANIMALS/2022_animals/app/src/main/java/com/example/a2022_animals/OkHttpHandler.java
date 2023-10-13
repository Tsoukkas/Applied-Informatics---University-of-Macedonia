package com.example.a2022_animals;
import android.os.*;
import org.json.*;
import java.util.*;
import okhttp3.*;

public class OkHttpHandler {

    public OkHttpHandler() {
        StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder().permitAll().build();
        StrictMode.setThreadPolicy(policy);
    }

    ArrayList<Animal> populateDropDown(String url) throws Exception {
        ArrayList<Animal> cbList = new ArrayList<>();
        OkHttpClient client = new OkHttpClient().newBuilder().build();
        RequestBody body = RequestBody.create("", MediaType.parse("text/plain"));
        Request request = new Request.Builder().url(url).method("POST", body).build();
        Response response = client.newCall(request).execute();
        String data = response.body().string();
        System.out.println("My Response: " + data);
        try {
            JSONObject json = new JSONObject(data);
            Iterator<String> keys = json.keys();
            while(keys.hasNext()) {
                String key = keys.next();
                String name = key;
                String type = json.getJSONObject(key).getString("type").toString();
                String voice = json.getJSONObject(key).getString("voice").toString();
                String image = json.getJSONObject(key).getString("image").toString();
                cbList.add(new Animal(name,type,voice,image));
            }
        } catch (JSONException e) {
            e.printStackTrace();
        }
        return cbList;
    }
}