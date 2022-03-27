package io.binac.leetcode;

/**
 * <p>Given a string <code>columnTitle</code> that represents the column title as appear in an Excel sheet, return <em>its corresponding column number</em>.</p>
 *
 * <p>For example:</p>
 *
 * <pre>A -&gt; 1
 * B -&gt; 2
 * C -&gt; 3
 * ...
 * Z -&gt; 26
 * AA -&gt; 27
 * AB -&gt; 28
 * ...
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> columnTitle = "A"
 * <strong>Output:</strong> 1
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> columnTitle = "AB"
 * <strong>Output:</strong> 28
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> columnTitle = "ZY"
 * <strong>Output:</strong> 701
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= columnTitle.length &lt;= 7</code></li>
 * 	<li><code>columnTitle</code> consists only of uppercase English letters.</li>
 * 	<li><code>columnTitle</code> is in the range <code>["A", "FXSHRXW"]</code>.</li>
 * </ul>
 */
public class ExcelSheetColumnNumber {
    public static class Solution1 {
        public int titleToNumber(String columnTitle) {
            int result = 0;
            for (int i = 0, e = columnTitle.length(); i < e; ++i)
                result = result * 26 + columnTitle.charAt(i) - 'A' + 1;
            return result;
        }
    }
}
