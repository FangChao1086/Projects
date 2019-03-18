# Music_recommendation
音乐推荐系统

## 文件介绍
### data
data存放数据文件，其中原始数据文件为playlistdetail.all.json，其他的文件都是此文件解析而来

### preproccess
parser  
解析歌单数据，将数据解析成 歌单+歌曲的格式  
例子：☀清新夏日☀清新男声控|我想漂浮感受磁场##欧美,电子,另类/独立##423245641##11355	414691355:::Lost (As I Am):::Superwalkers:::80.0	410802620:::Next Escape:::Viceroy:::100.0	419549837:::Silhouette:::Goldroom:::60.0 ...

processor  
将parser后的数据解析成suprise可接受的格式，UserId+ItemId+Rating+Timestamp;如下  
419935738,41665696,1.0,1300000  
419935738,185809,1.0,1300000  
419935738,27955652,1.0,1300000

dummper  
将歌单id与歌曲id映射成对应的名称

