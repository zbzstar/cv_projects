# homography_switch(通过单应矩阵拼接图像) rice_count(通过局部范围像素值做滤极限波) get_epipolar_line(通过极线约束计算基础矩阵和极线)
## description
### homography_switch
目标图
![目标图](https://github.com/zbzstar/pictures_markdown/raw/master/12.jpg)
原图
![原图](https://github.com/zbzstar/pictures_markdown/raw/master/1.jpg)
效果图
![效果图](https://github.com/zbzstar/pictures_markdown/raw/master/merge_baby.png)
### rice_count

原图  
![目标图](https://github.com/zbzstar/pictures_markdown/raw/master/rice.jpeg)  
选择范围  
![目标图](https://github.com/zbzstar/pictures_markdown/raw/master/rice_select.jpg)  
剪切图  
![目标图](https://github.com/zbzstar/pictures_markdown/raw/master/rice_grabcut.jpg)  
morphology图  
![目标图](https://github.com/zbzstar/pictures_markdown/raw/master/rice_morphology.jpg)

### get_epipolar_line
![目标图](https://github.com/zbzstar/pictures_markdown/raw/master/epi1.jpg)
![目标图](https://github.com/zbzstar/pictures_markdown/raw/master/epi2.jpg)
## compile depencies
* Eigen3
* opencv
## compile
```css
mkdir build
cd build
cmake ..
make 
```
## run
```
./homography_switch
```
选择要替换的位置的四个点（顺时针方向），回车后如效果图所示
```
./rice_count 
```
画出选择范围，按下“p”键，效果如果上图效果所示

```
./get_epipolar_line
```