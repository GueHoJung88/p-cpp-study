#!/usr/bin/env python3
"""
XML 테스트 결과를 HTML로 변환하는 스크립트
"""

import xml.etree.ElementTree as ET
import sys
import os
from datetime import datetime

def parse_test_results(xml_file):
    """XML 파일을 파싱하여 테스트 결과를 추출"""
    try:
        tree = ET.parse(xml_file)
        root = tree.getroot()
        
        results = {
            'total_tests': 0,
            'passed_tests': 0,
            'failed_tests': 0,
            'test_suites': []
        }
        
        for testsuite in root.findall('.//testsuite'):
            suite_name = testsuite.get('name', 'Unknown')
            total = int(testsuite.get('tests', 0))
            failures = int(testsuite.get('failures', 0))
            passed = total - failures
            
            suite_data = {
                'name': suite_name,
                'total': total,
                'passed': passed,
                'failed': failures,
                'tests': []
            }
            
            for testcase in testsuite.findall('testcase'):
                test_name = testcase.get('name', 'Unknown')
                test_time = float(testcase.get('time', 0))
                
                failure = testcase.find('failure')
                if failure is not None:
                    status = 'FAILED'
                    message = failure.get('message', '')
                else:
                    status = 'PASSED'
                    message = ''
                
                suite_data['tests'].append({
                    'name': test_name,
                    'status': status,
                    'time': test_time,
                    'message': message
                })
            
            results['test_suites'].append(suite_data)
            results['total_tests'] += total
            results['passed_tests'] += passed
            results['failed_tests'] += failures
        
        return results
    except Exception as e:
        print(f"XML 파싱 오류: {e}")
        return None

def generate_html(results, output_dir):
    """테스트 결과를 HTML로 생성"""
    if not results:
        return
    
    html_content = f"""
<!DOCTYPE html>
<html lang="ko">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>테스트 결과 리포트</title>
    <style>
        body {{
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            margin: 0;
            padding: 20px;
            background-color: #f5f5f5;
        }}
        .container {{
            max-width: 1200px;
            margin: 0 auto;
            background: white;
            border-radius: 8px;
            box-shadow: 0 2px 10px rgba(0,0,0,0.1);
            overflow: hidden;
        }}
        .header {{
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            color: white;
            padding: 30px;
            text-align: center;
        }}
        .stats {{
            display: flex;
            justify-content: space-around;
            padding: 20px;
            background: #f8f9fa;
        }}
        .stat {{
            text-align: center;
        }}
        .stat-number {{
            font-size: 2em;
            font-weight: bold;
        }}
        .passed {{ color: #28a745; }}
        .failed {{ color: #dc3545; }}
        .total {{ color: #007bff; }}
        .test-suite {{
            margin: 20px;
            border: 1px solid #ddd;
            border-radius: 5px;
        }}
        .suite-header {{
            background: #e9ecef;
            padding: 15px;
            font-weight: bold;
            border-bottom: 1px solid #ddd;
        }}
        .test-list {{
            padding: 0;
            margin: 0;
        }}
        .test-item {{
            padding: 10px 15px;
            border-bottom: 1px solid #eee;
            display: flex;
            justify-content: space-between;
            align-items: center;
        }}
        .test-item:last-child {{
            border-bottom: none;
        }}
        .test-status {{
            padding: 4px 8px;
            border-radius: 3px;
            font-size: 0.8em;
            font-weight: bold;
        }}
        .status-passed {{
            background: #d4edda;
            color: #155724;
        }}
        .status-failed {{
            background: #f8d7da;
            color: #721c24;
        }}
        .timestamp {{
            text-align: center;
            color: #666;
            margin-top: 20px;
        }}
    </style>
</head>
<body>
    <div class="container">
        <div class="header">
            <h1>🧪 테스트 결과 리포트</h1>
            <p>자동 생성된 테스트 결과 요약</p>
        </div>
        
        <div class="stats">
            <div class="stat">
                <div class="stat-number total">{results['total_tests']}</div>
                <div>총 테스트</div>
            </div>
            <div class="stat">
                <div class="stat-number passed">{results['passed_tests']}</div>
                <div>통과</div>
            </div>
            <div class="stat">
                <div class="stat-number failed">{results['failed_tests']}</div>
                <div>실패</div>
            </div>
        </div>
        
        <div class="test-suites">
"""

    for suite in results['test_suites']:
        html_content += f"""
            <div class="test-suite">
                <div class="suite-header">
                    📦 {suite['name']} 
                    <span style="float: right;">
                        {suite['passed']}/{suite['total']} 통과
                    </span>
                </div>
                <div class="test-list">
"""
        
        for test in suite['tests']:
            status_class = 'status-passed' if test['status'] == 'PASSED' else 'status-failed'
            html_content += f"""
                    <div class="test-item">
                        <div>
                            <strong>{test['name']}</strong>
                            <span style="color: #666; font-size: 0.9em;">({test['time']:.3f}s)</span>
                        </div>
                        <span class="test-status {status_class}">{test['status']}</span>
                    </div>
"""
            
            if test['message']:
                html_content += f"""
                    <div style="padding: 10px 15px; background: #fff3cd; border-left: 4px solid #ffc107; margin: 0 15px;">
                        <strong>오류 메시지:</strong><br>
                        <pre style="margin: 5px 0; white-space: pre-wrap;">{test['message']}</pre>
                    </div>
"""
        
        html_content += """
                </div>
            </div>
"""

    html_content += f"""
        </div>
        
        <div class="timestamp">
            생성 시간: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}
        </div>
    </div>
</body>
</html>
"""

    # HTML 파일 저장
    os.makedirs(output_dir, exist_ok=True)
    with open(os.path.join(output_dir, 'index.html'), 'w', encoding='utf-8') as f:
        f.write(html_content)

def main():
    if len(sys.argv) != 3:
        print("사용법: python3 xml_to_html.py <xml_file> <output_dir>")
        sys.exit(1)
    
    xml_file = sys.argv[1]
    output_dir = sys.argv[2]
    
    if not os.path.exists(xml_file):
        print(f"XML 파일을 찾을 수 없습니다: {xml_file}")
        sys.exit(1)
    
    results = parse_test_results(xml_file)
    if results:
        generate_html(results, output_dir)
        print(f"HTML 리포트가 생성되었습니다: {output_dir}/index.html")
    else:
        print("테스트 결과를 파싱할 수 없습니다.")
        sys.exit(1)

if __name__ == "__main__":
    main() 