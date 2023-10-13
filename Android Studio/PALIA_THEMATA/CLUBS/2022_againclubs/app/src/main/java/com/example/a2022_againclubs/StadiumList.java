package com.example.a2022_againclubs;

import java.util.ArrayList;

    public class StadiumList {
        ArrayList<Stadium> lista ;
        public StadiumList() {
            lista = new ArrayList<Stadium>();
            String url = "http://192.168.2.3/stadiums/getClubs.php";
            try {
                OkHttpHandler ok = new OkHttpHandler();
                lista = ok.getClubs(url);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

    public ArrayList<String> getNames(){
        ArrayList<String> onomata = new ArrayList<>();
        for(int i=0;i<lista.size();i++){
            onomata.add(lista.get(i).getName());
        }
        return onomata;
    }

    public ArrayList<String> getClubs(){
        ArrayList<String> onomata = new ArrayList<>();
        for(int i=0;i<lista.size();i++){
            onomata.add(lista.get(i).getClub());
        }
        return onomata;
    }

    public ArrayList<String> getFan_chant(){
        ArrayList<String> onomata = new ArrayList<>();
        for(int i=0;i<lista.size();i++){
            onomata.add(lista.get(i).getFan_chant());
        }
        return onomata;
    }

    public ArrayList<String> getImages(){
        ArrayList<String> onomata = new ArrayList<>();
        for(int i=0;i<lista.size();i++){
            onomata.add(lista.get(i).getImage());
        }
        return onomata;
    }

}
