package com.example.a2022_animals;

import java.util.ArrayList;

public class AnimalList {
    ArrayList<Animal> zoa = new ArrayList<>();

    public AnimalList(){
        String url = "http://195.251.211.64/animals/getAnimals.php";
        OkHttpHandler ok = new OkHttpHandler();
        try{
            zoa = ok.populateDropDown(url);
        }catch (Exception e){
            e.printStackTrace();
        }
    }



    public ArrayList<String> getNames(){
        ArrayList<String> lista = new ArrayList<>();
        for(int i=0;i< zoa.size();i++){
            lista.add(zoa.get(i).getName());
        }
        return  lista;
    }
    public ArrayList<String> getTypes(){
        ArrayList<String> lista = new ArrayList<>();
        for(int i=0;i< zoa.size();i++){
            lista.add(zoa.get(i).getType());
        }
        return lista;
    }

    public ArrayList<String> getVoices(){
        ArrayList<String> lista = new ArrayList<>();
        for(int i=0;i< zoa.size();i++){
            lista.add(zoa.get(i).getVoice());
        }
        return lista;
    }

    public ArrayList<String> getUrls(){
        ArrayList<String> lista = new ArrayList<>();
        for(int i=0;i< zoa.size();i++){
            lista.add(zoa.get(i).getImg());
        }
        return lista;
    }
}
