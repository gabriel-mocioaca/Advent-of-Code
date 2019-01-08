#include <bits/stdc++.h>
using namespace std;

ifstream in("input.txt");

int no_imm_syst, no_infec;

struct group{
    int no_units;
    int hp;
    string dmg_type;
    int dmg_val;
    vector<string> weakness;
    vector<string> immunity;
    int initiative;

    bool is_dead;
};


bool comp_ef_power(group a, group b){
    if((a.no_units * a.dmg_val) > (b.no_units * b.dmg_val))
        return true;
    else{
        if((a.no_units * a.dmg_val) == (b.no_units * b.dmg_val))
            return a.initiative > b.initiative;
    }
    return false;
}

vector<group> immune_syst;
vector<group> infection;
vector<group> both;

int bs;

void read_input(){
    int n;
    in >> n;
    no_imm_syst = n;
    for(int u = 0; u < n; ++u){
        int no_def;
        group x;
        in >> x.no_units >> x.hp;
        in >> no_def;
        for(int i = 1; i <= no_def; ++i){
            string type;
            int no_type;
            in >> type;
            in >> no_type;
            for(int j = 1; j <= no_type; ++j){
                string s;
                in >> s;
                if (type == "weak")
                    x.weakness.push_back(s);
                else
                    x.immunity.push_back(s);
            }
        }
        in >> x.dmg_val;
        x.dmg_val += bs;
        in >> x.dmg_type;
        in >> x.initiative;
        x.is_dead = false;
        immune_syst.push_back(x);
        both.push_back(x);
    }
    in >> n;
    no_infec = n;
    for(int u = 0; u < n; ++u){
        int no_def;
        group x;
        in >> x.no_units >> x.hp;
        in >> no_def;
        for(int i = 1; i <= no_def; ++i){
            string type;
            int no_type;
            in >> type;
            in >> no_type;
            for(int j = 1; j <= no_type; ++j){
                string s;
                in >> s;
                if (type == "weak")
                    x.weakness.push_back(s);
                else
                    x.immunity.push_back(s);
            }
        }
        in >> x.dmg_val;
        in >> x.dmg_type;
        in >> x.initiative;
        x.is_dead = false;
        infection.push_back(x);
        both.push_back(x);
    }
}

void output_info(){
    cout << "Immune System\n";
    for(auto it : immune_syst){
        cout << it.no_units << ' ' << it.hp << ' ' << it.dmg_val << ' ' << it.dmg_type << ' ' << it.initiative << endl;
        cout << "Weak:"; for(auto iti : it.weakness) cout << iti << ' '; cout << endl;
        cout << "Immune:"; for(auto iti : it.immunity) cout << iti << ' '; cout << endl;
        cout << "Is dead? " << (it.is_dead ? "Yes" : "No") << endl;

    }
    cout << "\nInfection\n";
    for(auto it : infection){
        cout << it.no_units << ' ' << it.hp << ' ' << it.dmg_val << ' ' << it.dmg_type << ' ' << it.initiative << endl;
        cout << "Weak:"; for(auto iti : it.weakness) cout << iti << ' '; cout << endl;
        cout << "Immune:"; for(auto iti : it.immunity) cout << iti << ' '; cout << endl;
        cout << "Is dead? " << (it.is_dead ? "Yes" : "No") << endl;

    }
}

int dmg_mult(group attacker, group defender){
    for(auto it : defender.immunity)
        if(it == attacker.dmg_type)
            return 0;
    for(auto it : defender.weakness)
        if(it == attacker.dmg_type)
            return 2;
    return 1;
}

int get_imm_syst_target(group x, vector<bool> chosen){
    int maxdmg = INT_MIN, maxep = INT_MIN, maxinit = INT_MIN;
    int chosenI = -1;
    for(int i = 0; i < infection.size(); ++i){
        if (!infection[i].is_dead && !chosen[i]){
            int dmg = x.dmg_val * x.no_units * dmg_mult(x, infection[i]);
            if (dmg > maxdmg){
                maxdmg = dmg;
                maxep = infection[i].dmg_val * infection[i].no_units;
                maxinit = infection[i].initiative;
                chosenI = i;
            }
            else{
                if (dmg == maxdmg){
                    if (infection[i].dmg_val * infection[i].no_units > maxep){
                        maxep = infection[i].dmg_val * infection[i].no_units;
                        maxinit = infection[i].initiative;
                        chosenI = i;
                    }
                    else{
                        if (infection[i].dmg_val * infection[i].no_units == maxep){
                            if (infection[i].initiative > maxinit){
                                maxinit = infection[i].initiative;
                                chosenI = i;
                            }
                        }
                    }
                }
            }
        }
    }
    if (maxdmg <= 0)
        chosenI = -1;
    return chosenI;
}

int get_infection_target(group x, vector<bool> chosen){
    int maxdmg = INT_MIN, maxep = INT_MIN, maxinit = INT_MIN;
    int chosenI = -1;
    for(int i = 0; i < immune_syst.size(); ++i){
        if (!immune_syst[i].is_dead && !chosen[i]){
            int dmg = x.dmg_val * x.no_units * dmg_mult(x, immune_syst[i]);
            if (dmg > maxdmg){
                maxdmg = dmg;
                maxep = immune_syst[i].dmg_val * immune_syst[i].no_units;
                maxinit = immune_syst[i].initiative;
                chosenI = i;
            }
            else{
                if (dmg == maxdmg){
                    if (immune_syst[i].dmg_val * immune_syst[i].no_units > maxep){
                        maxep = immune_syst[i].dmg_val * immune_syst[i].no_units;
                        maxinit = immune_syst[i].initiative;
                        chosenI = i;
                    }
                    else{
                        if (immune_syst[i].dmg_val * immune_syst[i].no_units == maxep){
                            if (immune_syst[i].initiative > maxinit){
                                maxinit = immune_syst[i].initiative;
                                chosenI = i;
                            }
                        }
                    }
                }
            }
        }
    }
    if (maxdmg <= 0)
        chosenI = -1;
    return chosenI;
}

void target_phase(vector<int> &immune_syst_target, vector<int> &infection_target){

    vector<bool> immune_syst_chosen(immune_syst.size() + 1, false);
    vector<bool> infection_chosen(infection.size() + 1, false);
    sort(immune_syst.begin(), immune_syst.end(), comp_ef_power);
    sort(infection.begin(), infection.end(), comp_ef_power);

    for(int i = 0; i < infection.size(); ++i){
        int chosenI = get_infection_target(infection[i], immune_syst_chosen);

        infection_target[i] = chosenI;
        if(chosenI != -1) immune_syst_chosen[chosenI] = true;
    }

    for(int i = 0; i < immune_syst.size(); ++i){
        int chosenI = get_imm_syst_target(immune_syst[i], infection_chosen);
        immune_syst_target[i] = chosenI;
        if(chosenI != -1) infection_chosen[chosenI] = true;
    }
}

void attack(group &attacker, group &defender){
    int dmg = attacker.no_units * attacker.dmg_val * dmg_mult(attacker, defender);
    defender.no_units -= dmg / defender.hp;
    //cout << "for " << dmg << " damage kills " << dmg / defender.hp << " units\n";
    if(defender.no_units <= 0)
        defender.is_dead = true;
}

void attack_phase(){
    vector<int> immune_syst_target(immune_syst.size() + 1, 0);
    vector<int> infection_target(infection.size() + 1, 0);
    target_phase(immune_syst_target, infection_target);

    /*for(int i = 0; i < infection.size(); ++i)
        cout << i << ' ' << infection_target[i] << '\n';

    for(int i = 0; i < immune_syst.size(); ++i)
        cout << i << ' ' << immune_syst_target[i] << '\n';*/



    for(int i = 0; i < both.size();++i){
        if(!both[i].is_dead){
            bool imm_found = false, infect_found = false;
            int im, in;
            for(im = 0; im < immune_syst.size(); ++im){
                if(both[i].initiative == immune_syst[im].initiative){
                    imm_found = true;
                    break;
                }
            }
            for(in = 0; in < infection.size(); ++in){
                if(both[i].initiative == infection[in].initiative){
                    infect_found = true;
                    break;
                }
            }
            if (imm_found){
                if(immune_syst_target[im] == -1) continue;
                if(!immune_syst[im].is_dead && !infection[immune_syst_target[im]].is_dead){
                   //cout << "Immune system " << im << " attacks infection " << immune_syst_target[im];

                    attack(immune_syst[im], infection[immune_syst_target[im]]);
                    if(infection[immune_syst_target[im]].is_dead) no_infec--;
                }
            }
            else{
                if(infection_target[in] == -1) continue;
                if(!infection[in].is_dead && !immune_syst[infection_target[in]].is_dead){
                   //cout << "Infection " << in << " attacks immune system " << infection_target[in];

                    attack(infection[in], immune_syst[infection_target[in]]);
                    if(immune_syst[infection_target[in]].is_dead) no_imm_syst--;
                }
            }
        }
    }

}

int main(){

    bs = 0;

    read_input();



    sort(both.begin(),both.end(), [](group a, group b){
            return a.initiative > b.initiative;
         });

    while(no_imm_syst > 0 &&  no_infec > 0){
        attack_phase();
        cout << " imm " << no_imm_syst << " infec " << no_infec << "\n\n";
        //if (no_imm_syst == 1 && no_infec == 1){output_info();break;}

    }
    int sum = 0;
    for(auto it : infection){

        if(!it.is_dead)
            sum += it.no_units;
    }
    cout << "\n\n" << sum;

    sum = 0;
    for(auto it : immune_syst){

        if(!it.is_dead)
            sum += it.no_units;
    }
    cout << "  " << sum;

}
