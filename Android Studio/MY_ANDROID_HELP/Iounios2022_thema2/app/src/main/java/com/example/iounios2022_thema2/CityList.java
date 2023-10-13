package com.example.iounios2022_thema2;

import java.util.ArrayList;

public class CityList {
    ArrayList<city> list = new ArrayList<>();

    public CityList(){
        OkHttpHandler ok = new OkHttpHandler();
        String url = "http://192.168.2.3/polis/getCities.php";
        try{
            list = ok.getCities(url);
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    public ArrayList<String> getNames(){
        ArrayList<String> lista = new ArrayList<>();
        for(int i=0;i<list.size();i++){
            lista.add(list.get(i).getName());
        }
        return lista ;
    }

    public ArrayList<String> getMonuments(){
        ArrayList<String> lista = new ArrayList<>();
        for(int i=0;i<list.size();i++){
            lista.add(list.get(i).getMonument());
        }
        return lista ;
    }

    public ArrayList<String> getCountry(){
        ArrayList<String> lista = new ArrayList<>();
        for(int i=0;i<list.size();i++){
            lista.add(list.get(i).getCountry());
        }
        return lista ;
    }

    public ArrayList<String> getImage(){
        ArrayList<String> lista = new ArrayList<>();
        for(int i=0;i<list.size();i++){
            lista.add(list.get(i).getImage());
        }
        return lista ;
    }

}
