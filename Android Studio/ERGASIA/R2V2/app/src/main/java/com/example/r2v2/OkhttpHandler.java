package com.example.r2v2;
import android.os.*;
import org.json.*;
import java.util.*;
import okhttp3.*;
public class OkhttpHandler {
    public OkhttpHandler() {
        StrictMode.ThreadPolicy policy = new
                StrictMode.ThreadPolicy.Builder().permitAll().build();
        StrictMode.setThreadPolicy(policy);
    }

    public void createProvision(String url) throws Exception {
        OkHttpClient client = new OkHttpClient().newBuilder().build();
        RequestBody body = RequestBody.create("",
                MediaType.parse("text/plain"));
        Request request = new Request.Builder().url(url).method("POST",
                body).build();
        Response response = client.newCall(request).execute();
        System.out.println("My Response: " + response);
    }
}
