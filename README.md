<h3>⚙️ BTS7960 Driver DC Motor PID Control</h3> 
<hr>
<h4>❓Proje Hakkında</h4>
<p>
  Bu projenin amacı BTS7960 Motor sürücüsünü P kanal IRF5305, N kanal IRFZ44N ve anahtarlama elemanı olarak BC547 transistörlerini kullanarak H-Bridge yapısıyla 
  yeniden tasarlamaktır. Tasarlanan sürücüyü bir encodere sahip olan DC motoru PID Kontrol algoritmasıyla kontrol etmektir. Simülasyon ve tasarım programı olarak 
  Proteus kullanılmıştır. Motorun matematiksel modellemesi içinse MATLAB/Simulink kullanılmıştır. Yazılım bölümünde ise mikrodenetleyici olarak Arduino Uno ve IDE ortamı olarak Arduino IDE kullanılmıştır.
</p>
<hr>
<h4>🛠️ Kullanılan Araçlar ve Programlar</h4>
<ul>
  <li>🔬 <b>Simülasyon ve Tasarım:</b> Proteus 8.16</li>
  <li>📐 <b>Matematiksel Modelleme:</b> MATLAB/Simulink</li>
  <li>💻 <b>Tümleşik Geliştirme Ortamı (IDE):</b> Arduino IDE</li>
</ul>
<hr>
<h4>📟 Devrede Kullanılan Komponentler</h4>
<ul>
  <li><b>P-Kanal MOSFET:</b> IRF5305</li> 
  <li><b>N-Kanal MOSFET:</b> IRFZ44N</li>
  <li><b>Anahtarlama Transistörü:</b> BC547 (BJT)</li>
  <li><b>Direnç:</b> 10k Ohm ve 1k Ohm</li> 
  <li><b>Güç Kaynağı:</b> 24V DC</li> 
  <li><b>Motor:</b> Encoder DC Motor</li>
  <li><b>Kontrolcü:</b> Arduino Uno</li>
  <li><b>Lojik Kapı:</b> Tampon (Buffer) Entegresi</li>
</ul>
<hr>
<h4>🚀 Kurulum ve Çalıştırma</h4>
<ol>
  <li><b>Depoyu Klonlayın:</b> 
    <code>git clone https://github.com/Ayberk-Aktan/BTS7960_Driver_DC_Motor_PID_Control.git</code>
  </li>
  <li><b>Arduino IDE Hazırlığı:</b> 
    <ul>
      <li><code>Code</code> klasöründeki dosyayı açın.</li>
      <li>Dosya > Tercihler (Preferences) kısmından <b>"Derleme" (Compilation)</b> kutucuğunu işaretleyin.</li>
      <li>Kodu derleyin (Taslak > Doğrula/Derle) ve alt paneldeki <code>.hex</code> uzantılı dosya yolunu kopyalayın.</li>
    </ul>
  </li>
  <li><b>Proteus Entegrasyonu:</b> 
    <ul>
      <li><code>Simulation</code> klasöründeki dosyayı açın.</li>
      <li>Arduino Uno bileşenine <b>çift tıklayın</b>.</li>
      <li>"Program File" kısmına kopyaladığınız <code>.hex</code> dosya yolunu yapıştırın.</li>
    </ul>
  </li>
  <li><b>Simülasyonu Başlatın:</b> Sol alttaki "Play" butonuna basarak simülasyonu çalıştırın.</li>
  <li>
      <b>💡 MATLAB/Simulink Notu:</b> 
      <i>PID katsayılarının analizi ve sistem cevabı için <code>Simulink_Models</code> klasöründeki <code>.slx</code> dosyasını MATLAB ile açabilirsiniz.</i>
  </li>
</ol>
<hr>
<h4>⚖️ Lisans</h4> 
<p>
  Bu proje MIT lisansı ile lisanslanmıştır. Detaylı bilgi için LICENSE dosyasına göz atabilirsiniz.
</p>
<hr>
<h4>🔗 İletişim</h4>
<p>
  Proje ile ilgili sorularınız veya geri bildirimleriniz için benimle iletişime geçebilirsiniz:
  <ul>
    <li>LinkedIn: <a href="https://www.linkedin.com/in/ayberk-aktan-3553a524a/">Ayberk Aktan</a></li>
    <li>GitHub: <a href="https://github.com/Ayberk-Aktan">Ayberk-Aktan</a></li>
  </ul>
</p>
