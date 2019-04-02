# 音乐推荐系统
## 文件介绍
原始文件见百度云网盘，**data里面的playlistdetail.all.json文件需要解压**。项目使用整个文件夹，包括data  
链接：https://pan.baidu.com/s/1dMCfQm8WiHzOPb41-Qrc4g
提取码：cotu 

## 1.Data_transform_and_preprocessing.ipynb
### 数据解析
1. 解析歌单数据，将数据解析成 歌单+歌曲的格式  
例子：☀清新夏日☀清新男声控|我想漂浮感受磁场##欧美,电子,另类/独立##423245641##11355	414691355:::Lost (As I Am):::Superwalkers:::80.0	410802620:::Next Escape:::Viceroy:::100.0	419549837:::Silhouette:::Goldroom:::60.0 ...
2. 将经1解析后的数据解析成suprise可接受的格式UserId(歌单id)+ItemId(歌曲id)+Rating+Timestamp    

|UserId|ItemId|Rating|Timestamp|    
|-----|-----|-----|-----|
|419935738|419935738|1.0|1300000|  
|419935738|185809|1.0|1300000  
|419935738|27955652|1.0|1300000

3. 生成歌单id到歌单名的映射
4. 生成歌曲id到歌曲名的映射
