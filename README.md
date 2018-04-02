<style type="text/css">

    p {
        padding-left: 16px;
        display: block;
        list-style-type: none;
        font-family: consolas;
        font-weight: bold; }

    li { 
        font-family: consolas;
        font-weight: bold; }
    
    ol > li > p { padding-left: 0px; }

    p.title { 
        padding-left: 0px;
        font-family: "Helvetica Neue", Helvetica, "Segoe UI", Arial, freesans,sans-serif; 
        font-weight: normal; }

</style>

<script type='text/javascript'>

    window.onload = function() {
      var links = document.links;
      for (var i = 0, linksLength = links.length; i < linksLength; i++) {
        if (links[i].hostname != window.location.hostname) {
          links[i].target = '_blank';
        }
      }
    }

</script>

# README

<p class="title">這不是教學，只是個單純的筆記，所以會省略大量的語法說明。</p>

### Chapter 01

<p class="title">主要講解一個 C 程式的主要架構。</p>

001\. [第一個 C 程式](https://github.com/TakeOver5/C/blob/master/demo/Chapter-01/001.HelloWorld/HelloWorld.cpp)

### Chapter 02

<p class="title">示範格式化輸出入與變數的使用。</p>

002\. [輸出範例](https://github.com/TakeOver5/C/blob/master/demo/Chapter-02/002.PrintVar/PrintVar.cpp)

003\. [輸入範例](https://github.com/TakeOver5/C/blob/master/demo/Chapter-02/003.ScanVar/ScanVar.cpp)  

### Chapter 03

<p class="title">運算子與運算式的使用示範。</p>

004\. [各式運算子範例](https://github.com/TakeOver5/C/blob/master/demo/Chapter-03/004.BaseOperation/BaseOperation.cpp)

005\. [圓面積計算](https://github.com/TakeOver5/C/blob/master/demo/Chapter-03/005.CircularArea/CircularArea.cpp)

006\. [溫度轉換](https://github.com/TakeOver5/C/blob/master/demo/Chapter-03/006.TemperatureConversion/TemperatureConversion.cpp)

007\. [sizeof 運算子使用](https://github.com/TakeOver5/C/blob/master/demo/Chapter-03/007.Sizeof/Sizeof.cpp)

### Chapter 04

<p class="title">流程判斷 if 與 switch。</p>

008\. [閏年判斷](https://github.com/TakeOver5/C/blob/master/demo/Chapter-04/008.LeapYearJudgment/LeapYearJudgment.cpp)

009\. [季節判斷](https://github.com/TakeOver5/C/blob/master/demo/Chapter-04/009.SeasonJudgment/SeasonJudgment.cpp)

010\. [字元判斷](https://github.com/TakeOver5/C/blob/master/demo/Chapter-04/010.InputCharacterJudgement/InputCharacterJudgement.cpp)

### Chapter 05

<p class="title">迴圈結構 for 與 while。</p>

011\. [九九乘法表](https://github.com/TakeOver5/C/blob/master/demo/Chapter-05/011.NineNineTable/NineNineTable.cpp)

012\. [發現區間倍數](https://github.com/TakeOver5/C/blob/master/demo/Chapter-05/012.FindNumberMultiples/FindNumberMultiples.cpp)

### Extra ── 額外的簡單筆記。

001. [第一個 C 程式](https://www.evernote.com/shard/s504/sh/9ce14898-097a-4a2c-b235-6cf428a4a0ed/88a697b232adefb2bfd315bdfdd6595e)

002. [printf 引數說明](https://www.evernote.com/shard/s504/sh/e64fc2b2-da0c-4e58-bda4-05084a20993c/3ee53868ba2ab8ddc1173c574902a329)

003. [不要用 system("pause") 而是 getch()？](https://www.evernote.com/shard/s504/sh/3510a36b-f908-4176-b7bf-c659d7b67954/db2dab6438e9c1f52dd1d4270253aa46)

004. [三元運算子](https://www.evernote.com/shard/s504/sh/39237393-9fea-4ad9-9f31-c4fe5c1abfdd/252aa3962a15adcd6ca784a7d0581ea1)

005. [while 與 do...while](https://www.evernote.com/shard/s504/sh/6fbefe40-acf5-4a0e-990c-582a0019b205/9a3f9be1597c890c226a4902600e09e0)

006. 全域變數

007. 變數修飾字

008. 函式傳遞的兩種方式

009. main 函式的引數
