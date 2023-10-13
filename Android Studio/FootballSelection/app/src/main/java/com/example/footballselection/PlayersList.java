package com.example.footballselection;

import java.util.ArrayList;

public class PlayersList {
    ArrayList<Player> list = new ArrayList<>();


    public PlayersList() {
        String url = "http://192.168.2.3/goats/footballers.php";
        try {
            OkHttpHandler ok = new OkHttpHandler();
            list = ok.getPlayers(url);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public ArrayList<String> getNames(String type) {
        ArrayList<String> onomata = new ArrayList<>();
        for (int i = 0; i < list.size(); i++) {
            if(type.equals(list.get(i).type)){
            onomata.add(list.get(i).getName());
        } }
        return onomata;
    }

    public ArrayList<String> getTypes() {
        ArrayList<String> onomata = new ArrayList<>();
        for (int i = 0; i < list.size(); i++) {
            onomata.add(list.get(i).gettype());
        }
        return onomata;
    }


    public ArrayList<String> getImages(String type) {
        ArrayList<String> onomata = new ArrayList<>();
        for (int i = 0; i < list.size(); i++) {
            if(type.equals(list.get(i).type)){
            onomata.add(list.get(i).getImage());
        }}
        return onomata;
    }
}


