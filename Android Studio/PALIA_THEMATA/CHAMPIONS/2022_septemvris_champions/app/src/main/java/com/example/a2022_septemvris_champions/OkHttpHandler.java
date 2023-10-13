package com.example.a2022_septemvris_champions;
import android.os.*;
import org.json.*;
import java.util.*;
import okhttp3.*;

public class OkHttpHandler {

    public OkHttpHandler() {
        StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder().permitAll().build();
        StrictMode.setThreadPolicy(policy);
    }

    ArrayList<Clubs> populateDropDown(String url) throws Exception {
        ArrayList<Clubs> cbList = new ArrayList<>();
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
                String brand = keys.next();
                String image = json.getJSONObject(brand).getString("url").toString();
                String year = json.getJSONObject(brand).getString("year").toString();
                String name = json.getJSONObject(brand).getString("name").toString();
                cbList.add(new Clubs(name,year,image));
            }
        } catch (JSONException e) {
            e.printStackTrace();
        }
        return cbList;
    }
}