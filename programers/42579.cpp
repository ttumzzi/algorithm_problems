#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct music
{
    int genre, song, index;
    string genreName;
};

bool cmp(music a, music b)
{
    if (a.genre == b.genre)
    {
        if (a.song == b.song)
            return a.index < b.index;
        else
            return a.song > b.song;
    }
    else
        return a.genre > b.genre;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    map<string, int> m;
    vector<music> musics;

    for (int i = 0; i < genres.size(); i++)
        m[genres[i]] += plays[i];

    for (int i = 0; i < genres.size(); i++)
        musics.push_back({m[genres[i]], plays[i], i, genres[i]});

    sort(musics.begin(), musics.end(), cmp);

    int num = 0;
    string genreBefore = "";
    while (!musics.empty())
    {
        music musicFront = musics.front();
        if (musicFront.genreName.compare(genreBefore) == 0)
        {
            num++;
            if (num < 2)
            {
                num++;
                answer.push_back(musicFront.index);
            }
        }
        else
        {
            num = 0;
            genreBefore = musicFront.genreName;
            answer.push_back(musicFront.index);
        }

        musics.erase(musics.begin());
    }
    return answer;
}

int main()
{
    vector<int> v = solution(vector<string>{"classic", "pop", "classic", "classic", "pop"},
                             vector<int>{500, 600, 150, 800, 2500});
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
}