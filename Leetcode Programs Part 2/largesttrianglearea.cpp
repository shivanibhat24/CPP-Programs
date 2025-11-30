struct P{ long long x,y; P(long long X=0,long long Y=0):x(X),y(Y){} };
inline long long cross(const P&a,const P&b,const P&c){ return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x); }
class Solution{
public:
    double largestTriangleArea(vector<vector<int>>&points){
        int n=points.size();
        if(n<3) return 0.0;
        vector<P> pts; pts.reserve(n);
        for(auto &p:points) pts.emplace_back(p[0],p[1]);
        sort(pts.begin(),pts.end(),[](const P&a,const P&b){ return a.x==b.x? a.y<b.y : a.x<b.x; });
        vector<P> h; h.reserve(n*2);
        for(auto &p:pts){
            while(h.size()>=2 && cross(h[h.size()-2],h[h.size()-1],p) <= 0) h.pop_back();
            h.push_back(p);
        }
        size_t lower_sz = h.size();
        for(int i = (int)pts.size()-2; i>=0; --i){
            auto &p = pts[i];
            while(h.size()>lower_sz && cross(h[h.size()-2],h[h.size()-1],p) <= 0) h.pop_back();
            h.push_back(p);
        }
        if(h.size()>1) h.pop_back();
        int m = (int)h.size();
        if(m<3) return 0.0;
        long long best2 = 0;
        for(int i=0;i<m;i++){
            int k = i+2;
            for(int j=i+1;j<m;j++){
                if(k<=j) k = j+1;
                while(k+1 < m){
                    long long a = llabs(cross(h[i],h[j],h[k]));
                    long long b = llabs(cross(h[i],h[j],h[k+1]));
                    if(b > a) ++k; else break;
                }
                if(k < m){
                    long long area2 = llabs(cross(h[i],h[j],h[k]));
                    if(area2 > best2) best2 = area2;
                }
            }
        }
        return best2 * 0.5;
    }
};
