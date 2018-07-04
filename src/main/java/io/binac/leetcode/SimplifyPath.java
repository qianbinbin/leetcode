package io.binac.leetcode;

import java.util.Stack;

/**
 * Given an absolute path for a file (Unix-style), simplify it.
 * <p>
 * <p>For example,
 * <p>path = "/home/", => "/home"
 * <p>path = "/a/./b/../../c/", => "/c"
 * <p>
 * <p>Corner Cases:
 * <p>
 * <p>Did you consider the case where path = ""?
 * <p>In this case, you should return "/".
 * <p>Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 * <p>In this case, you should ignore redundant slashes and return "/home/foo".
 */
public class SimplifyPath {
    public static class Solution1 {
        public String simplifyPath(String path) {
            if (path.charAt(0) != '/')
                throw new IllegalArgumentException("invalid path");
            String files[] = path.split("/");
            Stack<String> stack = new Stack<>();
            for (String file : files) {
                switch (file) {
                    case "":
                        break;
                    case ".":
                        break;
                    case "..":
                        if (!stack.empty())
                            stack.pop();
                        break;
                    default:
                        stack.push(file);
                }
            }
            StringBuilder sb = new StringBuilder();
            for (String file : stack) {
                sb.append('/');
                sb.append(file);
            }
            if (sb.length() == 0) sb.append('/');
            return sb.toString();
        }
    }
}
