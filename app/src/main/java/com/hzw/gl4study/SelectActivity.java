package com.hzw.gl4study;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class SelectActivity extends AppCompatActivity{
    private Intent intent;
    private Bundle bundle;
    private Button btn_1;
    private Button btn_2;
    private Button btn_3;
    private Button btn_4;
    private Button btn_cam;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_select);
        init();
        intent = new Intent(SelectActivity.this, MainActivity.class);
        bundle = new Bundle();
        btn_1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                bundle.putInt("SampleType",0);
                intent.putExtras(bundle);
                startActivity(intent);
            }
        });
        btn_2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                bundle.putInt("SampleType",1);
                intent.putExtras(bundle);
                startActivity(intent);
            }
        });
        btn_3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                bundle.putInt("SampleType",2);
                intent.putExtras(bundle);
                startActivity(intent);
            }
        });
        btn_4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                bundle.putInt("SampleType",3);
                intent.putExtras(bundle);
                startActivity(intent);
            }
        });
    }

    public void init(){
        btn_1 = findViewById(R.id.btn_1);
        btn_2 = findViewById(R.id.btn_2);
        btn_3 = findViewById(R.id.btn_3);
        btn_4 = findViewById(R.id.btn_4);
        btn_cam = findViewById(R.id.btn_5);
    }
}