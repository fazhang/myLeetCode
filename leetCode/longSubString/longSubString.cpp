#include <stdio.h> 
#include <string>  
#include <iostream>  
#include <vector>  
#include <iomanip>
#include <memory>
#include <regex>
#include <map>
#include <sys/time.h>
using namespace std;

uint64_t  Nowms()
{
  timeval tvNow;
  gettimeofday(&tvNow, NULL);
  return tvNow.tv_sec* 1000 +  tvNow.tv_usec/1000;
}
void outputVec(const vector<int>& in){
    size_t sep = 10;
    size_t cnt = 0;
    for( auto i : in){
        cout <<setiosflags(ios::left)<<setw(8);
        cout << i << " ";
        if( (cnt)%sep == 9){
            cout << endl;
        }
        cnt ++;
    }
    cout << endl;
}


int findMaxSubString(const string& in){
    std::regex ws_re("\\s+"); // whitespace
    std::vector<std::string> v(std::sregex_token_iterator(in.begin(), in.end(), ws_re, -1), 
    std::sregex_token_iterator());

    int i = 0;
    for( auto s : v ){
        cout << i++ <<  " "  << s << endl;
    }

    std::vector<int> dp(v.size());

    map<string, int>  mapChar2Index;
    int maxLen = 0 ;
    int inSize = v.size();
    int maxIndex = 0 ;
    int start = 0 ;

    for( int k = 0 ; k < inSize ; k++){
        const string& t = v[k];
        auto it = mapChar2Index.find(t);
        if( it != mapChar2Index.end()){
            start = std::max(it->second+1,start);
        }
        mapChar2Index[t] = k;
        dp[k] = k - start +1;
        if( dp[k] > maxLen){
            maxLen = dp[k];
            maxIndex = k;
        }
    }

    cout << "maxLen:" << maxLen << " maxIndex:" << maxIndex << endl;
    outputVec(dp);

    return maxLen;

}


int main(int argc, char**argv){
    std::string text = "overall_hot_search_list overall_smartbox overall_search_results_page download_comp_page record_module record_audio_song_page overall_hot_search_list overall_search_history_page overall_smartbox overall_search_results_page overall_search_history_page overall_hot_search_list overall_smartbox overall_search_results_page details_of_comp_page download_comp_page record_module record_audio_song_page details_of_comp_page overall_search_history_page overall_hot_search_list overall_smartbox overall_search_results_page download_comp_page record_module record_audio_song_page download_comp_page overall_search_history_page overall_hot_search_list overall_search_results_page overall_smartbox overall_search_history_page overall_hot_search_list overall_smartbox overall_search_results_page record_module download_comp_page record_module record_audio_song_page record_module record_audio_song_page overall_search_history_page overall_hot_search_list overall_search_history_page feed_following overall_hot_search_list overall_smartbox overall_search_results_page record_module record_audio_song_page";
    findMaxSubString(text);

    return 0;
}
