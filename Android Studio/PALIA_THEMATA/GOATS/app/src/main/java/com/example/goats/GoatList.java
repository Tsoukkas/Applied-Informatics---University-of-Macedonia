package com.example.goats;
import java.util.ArrayList;

public class GoatList {
    ArrayList<Goat> lista ;
    public GoatList() {
        lista = new ArrayList<Goat>();
        String url = "http://192.168.2.3/goats/players.php";
        try {
            OkHttpHandler ok = new OkHttpHandler();
            lista = ok.getPlayers(url);
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

    public ArrayList<Integer> getTr(){
        ArrayList<Integer> tropea = new ArrayList<>();
        for(int i=0;i<lista.size();i++){
            tropea.add(lista.get(i).getTr());
        }
        return tropea;
    }

    public ArrayList<Integer> getTotal(){
        ArrayList<Integer> total = new ArrayList<>();
        for(int i=0;i<lista.size();i++){
            total.add(lista.get(i).getTotalGA());
        }
        return total;
    }

    public ArrayList<String> getImages(){
        ArrayList<String> imges = new ArrayList<>();
        for(int i=0;i<lista.size();i++){
            imges.add(lista.get(i).getImage());
        }
        return imges;
    }

}
